SYSCALL_DEFINE2(sh_task_info, char *, file, int, msg)
{
  char file2[256];
  long copy = strncpy_from_user(file2, file, sizeof(file));	
  struct task_struct *pid_task;
  pid_task = find_task_by_vpid(msg);
  if(pid_task == NULL){
  	return -ESRCH;
  }
  printk(KERN_EMERG "%d\n", pid_task->prio);
  printk(KERN_EMERG "%d\n", pid_task->pdeath_signal);
  printk(KERN_EMERG "%d\n", pid_task->link_count);
  printk(KERN_EMERG "%d\n", pid_task->exit_signal);
  printk(KERN_EMERG "%d\n", pid_task->static_prio);

  struct file *file1 = filp_open(file2, O_WRONLY|O_CREAT, 0644);

  if (IS_ERR(file1)){
  	printk(KERN_EMERG "filp_open error\n");
  	return PTR_ERR(file1);
  }else{
  	char buf1[20];
  	sprintf(buf1, "%d", pid_task->prio);
  	kernel_write(file1, buf1, strlen(buf1), &(file1->f_pos));

  	char buf2[20];
  	sprintf(buf2, "%d", pid_task->pdeath_signal);
  	kernel_write(file1, buf2, strlen(buf2), &(file1->f_pos));

  	char buf3[20];
  	sprintf(buf3, "%d", pid_task->link_count);
  	kernel_write(file1, buf3, strlen(buf3), &(file1->f_pos));

  	char buf4[20];
  	sprintf(buf4, "%d", pid_task->exit_signal);
  	kernel_write(file1, buf4, strlen(buf4), &(file1->f_pos));

  	char buf5[20];
  	sprintf(buf5, "%d", pid_task->static_prio);
  	kernel_write(file1, buf5, strlen(buf5), &(file1->f_pos));

  	filp_close(file1, NULL)
  }

  // printk(KERN_EMERG "sh_task_info syscall called with \"%s\"\n", buf);
  return 0;
}
