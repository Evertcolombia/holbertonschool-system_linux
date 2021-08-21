#!/usr/bin/python3

'''             
Locates and replaces the first occurrence of a string in the heap of a process

Usage: ./read_write_heap.py PID search_string replace_by_string

Where:
    - PID is the pid of the target process
    - search_string is the ASCII string you are looking to overwrite
    - replace_by_string is the ASCII string you want to replace search_string with
'''


import sys

def default_exit(msg):
    print("\n{}".format(msg))
    sys.exit(1)

def validate_str(to_validate):
    if to_validate == "":
        deafult_exit()
    return to_validate

if len(sys.argv) != 4:
    default_exit("Args must be 3")

try:
    pid = int(sys.argv[1]) # pid of the process
    if pid <= 0:
        default_exit("[err] pid must be greather than 0")
except ValueError as e:
    default_exit(e)

# search and replace strings
search_str = validate_str(sys.argv[2]) 
replace_str = validate_str(sys.argv[3])

# path's to maps and mem files for current pid
maps_path = "/proc/{}/maps".format(pid)
mem_path = "/proc/{}/mem".format(pid)
print("\npath's to use: {} - {}\n".format(maps_path, mem_path))

try:
    maps_lines = open(maps_path, 'r')
except IOError as e:
    default_exit(e)

# search the heap information
heap_line = list()
print("Searching heap on maps file")
for line in maps_lines:
    line = line.split()
    if line[-1][:] == "[heap]":
        heap_line = line
        print("Heap was found!")
        break
maps_lines.close()

# parse the heap line
perms = heap_line[1]
if 'w' not in perms and 'r' not in perms:
    default_exit("[err] does not have read write perms")
    exit(1)

addr = heap_line[0].split("-")
if len(addr) != 2:
    default_exit("[err] wrong address format")
addr_start = int(addr[0], 16)
addr_end = int(addr[1], 16)

offset = heap_line[2]
dev = heap_line[3]
inode = heap_line[4]
path = heap_line[-1][:]
print("\tPath: {}\n\tAdress: {}\n\tPerms: {}\n\tOffset: {} \
        \n\tDev: {}\n\tInode: {}"
        .format(path, '-'.join(addr), perms, offset, dev, inode))
print("start: {}\nend: {}".format(addr_start, addr_end))

# open and read mem file
try:
    mem_lines = open(mem_path, 'rb+')
except IOError as e:
    default_exit(e)

# search the heap on virtual memory
mem_lines.seek(addr_start)
heap = mem_lines.read(addr_end - addr_start)

# search the string in the heap
try:
    i = heap.index(bytes(search_str, "ASCII"))
except:
    mem_lines.close()
    default_exit("[err] cant find {}".format(search_str))
print("Found search string {} at {:x}".format(search_str, i))

# write the new string in the heap
mem_lines.seek(addr_start + i)
mem_lines.write(bytes(replace_str, "ASCII"))
mem_lines.close()
print("write {} at {:x}".format(replace_str, addr_start + i))
print("well done!")
