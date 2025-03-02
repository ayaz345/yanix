#include <fs/vfs.h>
#include <kernel.h>
#include <libk/string.h>
#include <proc/tasking.h>
#include <kernel/user.h>

char *getline()
{
	char buf[LOGIN_LEN];
	int  len     = vfs_read_fd(0, buf, LOGIN_LEN);
	buf[len - 1] = '\0';

	return strdup(buf);
}

int login()
{
	user_login("root", "password");
	return 1;
	
	while (1)
	{
		printk("Login: ");
		char *login = getline();
		printk("Password: ");
		char *passwd = getline();

		printk("'%s' '%s'\n", login, passwd);
		if (!user_login(login, passwd))
			break;

		printk("Incorrect, please try again\n");
	}

	get_current_task()->cwd = strdup(get_current_user()->home);

	printk("Welcome %s\n", get_current_user()->name);
	return 1;
}