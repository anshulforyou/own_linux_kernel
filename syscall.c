SYSCALL_DEFINE2(sh_task_info, char *, file, int, msg)
{
  char file2[256];
  long copy = strncpy_from_user(file2, file, sizeof(file2));	
  struct task_struct *pid_task;
  pid_task = find_task_by_vpid(msg);
  if(pid_task == NULL){
  	return -ESRCH;
  }
  printk(KERN_EMERG "%s %d\n", "Prio field ", pid_task->prio);
  printk(KERN_EMERG "%s %d\n", "Pdeath_signal field ", pid_task->pdeath_signal);
  printk(KERN_EMERG "%s %d\n", "Normal_prio field ", pid_task->normal_prio);
  printk(KERN_EMERG "%s %d\n", "Exit_signal field ", pid_task->exit_signal);
  printk(KERN_EMERG "%s %d\n", "Static_prio field ", pid_task->static_prio);

  struct file *file1 = NULL;
  file1 = filp_open(file2, O_CREAT | O_WRONLY, 0644);

  if (IS_ERR(file1)){
  	printk(KERN_EMERG "filp_open error\n");
  	return PTR_ERR(file1);
  }else{
  	char buf1[20];
  	sprintf(buf1, "%d", pid_task->prio);
  	kernel_write(file1, "Prio field ", strlen("Prio field "), &(file1->f_pos));
  	kernel_write(file1, buf1, strlen(buf1), &(file1->f_pos));
  	kernel_write(file1, "\n", strlen("\n"), &(file1->f_pos));

  	char buf2[20];
  	sprintf(buf2, "%d", pid_task->pdeath_signal);
  	kernel_write(file1, "Pdeath_signal field ", strlen("Pdeath_signal field "), &(file1->f_pos));
  	kernel_write(file1, buf2, strlen(buf2), &(file1->f_pos));
  	kernel_write(file1, "\n", strlen("\n"), &(file1->f_pos));

  	char buf3[20];
  	sprintf(buf3, "%d", pid_task->normal_prio);
  	kernel_write(file1, "Normal_prio field ", strlen("Normal_prio field "), &(file1->f_pos));
  	kernel_write(file1, buf3, strlen(buf3), &(file1->f_pos));
  	kernel_write(file1, "\n", strlen("\n"), &(file1->f_pos));

  	char buf4[20];
  	sprintf(buf4, "%d", pid_task->exit_signal);
  	kernel_write(file1, "Exit_signal field ", strlen("Exit_signal field "), &(file1->f_pos));
  	kernel_write(file1, buf4, strlen(buf4), &(file1->f_pos));
  	kernel_write(file1, "\n", strlen("\n"), &(file1->f_pos));

  	char buf5[20];
  	sprintf(buf5, "%d", pid_task->static_prio);
  	kernel_write(file1, "Static_prio field ", strlen("Static_prio field "), &(file1->f_pos));
  	kernel_write(file1, buf5, strlen(buf5), &(file1->f_pos));
  	kernel_write(file1, "\n", strlen("\n"), &(file1->f_pos));
  	
  	filp_close(file1, NULL);
  }

  return 0;
}