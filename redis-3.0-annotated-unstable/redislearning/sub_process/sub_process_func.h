extern int global_vars;
void Echo(int count, bool is_subprocess);

static void charatatime(char *);

void TELL_WAIT(void);
void TELL_PARENT(void);
void TELL_CHILD(void);
void WAIT_PARENT(void);
void WAIT_CHILD(void);