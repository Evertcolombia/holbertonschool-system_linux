#include <Python.h>

void print_python_list(PyObject *p)
{
	int count = 0;
	PyListObject *ptr;

	ptr = (PyListObject *)p;
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %d\n", (int)(PyList_Size(p)));
	/*printf("[*] Allocated = %d\n", (int)ptr->allocated);*/

	for (count = 0; count < (int)(PyList_Size(p)); count++)
	{
		printf("Element %d: %s\n", count, Py_TYPE(ptr->ob_item[count])->tp_name);
	}
}
