
#include <stdlib.h>
#include <stdio.h>

extern char ** environ;	/* �ñ�������ϵͳ�����ĵ�ַ */

int main()
{
	char **env = environ;
	
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	
	printf("\nPATH=%s\n", getenv("PATH"));	/* getenv��ȡĳ������������ֵ */
	
	putenv("ENVTEST=test_putenv");	/* putenv���ӻ�ı价��������ֵ */
	printf("\nENVTEST=%s\n", getenv("ENVTEST"));
	
	/* int setenv(const char *name, const char *value, int overwrite); overwrite�����Ƿ񸲸��Ѿ����ڵ�ֵ */
	setenv("ENVTEST", "test_setenv", 1);
	printf("\nENVTEST=%s\n", getenv("ENVTEST"));
	
	unsetenv("ENVTEST");
	printf("\nENVTEST=%s\n", getenv("ENVTEST"));
	
	exit(0);
}