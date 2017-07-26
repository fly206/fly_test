#include<dlfcn.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	void *pHandle;
	void(*pFunc)();
	int *p;
	pHandle = dlopen("./dtest1.so", RTLD_NOW);
	if(!pHandle){
		printf("Can't fidn dtest1.so\n");
		exit(1);
	}
	pFunc = (void (*)())dlsym(pHandle, "print");
	if(pFunc)
		pFunc();
	else
		printf("Can't find function print\n");
	p = (int*)dlsym(pHandle, "p");
	if(p)
		printf("p = %d\n", *p);
	else
		printf("Can't find int p\n");
	dlclose(pHandle);
	return 0;
}
