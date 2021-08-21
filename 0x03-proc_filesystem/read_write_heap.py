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

def default_exit():
    print("bad usage")
    exit(1)

def validate_str(to_validate):
    if to_validate == "":
        deafult_exit()
    return to_validate

if len(sys.argv) != 4:
    default_exit()
try:
    pid = int(sys.argv[1]) # pid of the process
    if pid <= 0:
        print("pid must be greather than 0")
        exit(1)
except ValueError:
    default_exit()

# search and replace strings
search_str = validate_str(sys.argv[2]) 
replace_str = validate_str(sys.argv[3])

maps_path = "/proc/{}/maps".format(pid)
print("maps path: {}".format(maps_path))
mem_path = "/proc/{}/mem".format(pid)
print("mem path: {}".format(mem_path))

try:
    maps_lines = open(maps_path, 'r')
except IOError as e:
    maps_lines.close()
    print(e)
    exit()

heap_line = list()
for line in maps_lines: # search heap information
    line = line.split()
    if line[-1][:] == "[heap]":
        heap_line = line
        print("heap found!")
        break

maps_lines.close()
# parse the heap line
perms = heap_line[1]
if 'w' not in perms and 'r' not in perms:
    print("does not have read write perms")
    exit(1)

addr = heap_line[0].split("-")
if len(addr) != 2:
    print("wrong address format")
    exit(1)
addr_start = int(addr[0], 16)
addr_end = int(addr[1], 16)

offset = heap_line[2]
dev = heap_line[3]
inode = heap_line[4]
pathname = heap_line[-1][:]

print("{}\n{}\n{}\n{}\n{}\n{}".format(
    '-'.join(addr), perms, offset, dev, inode, pathname))
print("start: {}\nend: {}".format(addr_start, addr_end))

# open and read mem file
try:
    mem_lines = open(mem_path, 'rb+')
except IOError as e:
    mem_lines.close()
    print(e)
    exit(1)

# search the heap on virtual memory
mem_lines.seek(addr_start)
heap = mem_lines.read(addr_end - addr_start)

#print(heap)

# search the string in the heap
try:
    i = heap.index(bytes(search_str, "ASCII"))
except:
    mem_lines.close()
    print("cant find {}".format(search_str))
    exit(1)
print("found {} at {:x}".format(search_str, i))

# write the new string in the heap
print("write {} at {:x}".format(replace_str, addr_start + i))
mem_lines.seek(addr_start + i)
mem_lines.write(bytes(replace_str, "ASCII"))

mem_lines.close()
