SYSCALL_DEFINE2(sh_task_info, char *, file, int, msg)
{
  struct task_struct *pid_task;
  pid_task = find_task_by_vpid(msg);
  printk(KERN_EMERG "%d\n", pid_task->prio);
  printk(KERN_EMERG "%d\n", pid_task->pdeath_signal);
  printk(KERN_EMERG "%d\n", pid_task->link_count);
  printk(KERN_EMERG "%d\n", pid_task->exit_signal);
  printk(KERN_EMERG "%d\n", pid_task->static_prio);

  struct file *filp_open(file);

  // printk(KERN_EMERG "sh_task_info syscall called with \"%s\"\n", buf);
  return 0;
}
