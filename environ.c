
#include <stdlib.h>
#include <stdio.h>

extern char ** environ;	/* 该变量保存系统变量的地址 */

int main()
{
	char **env = environ;
	
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	
	printf("\nPATH=%s\n", getenv("PATH"));	/* getenv获取某个环境变量的值 */
	
	putenv("ENVTEST=test_putenv");	/* putenv增加或改变环境变量的值 */
	printf("\nENVTEST=%s\n", getenv("ENVTEST"));
	
	/* int setenv(const char *name, const char *value, int overwrite); overwrite决定是否覆盖已经存在的值 */
	setenv("ENVTEST", "test_setenv", 1);
	printf("\nENVTEST=%s\n", getenv("ENVTEST"));
	
	unsetenv("ENVTEST");
	printf("\nENVTEST=%s\n", getenv("ENVTEST"));
	
	exit(0);
}