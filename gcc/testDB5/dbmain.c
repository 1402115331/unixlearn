#include <stdio.h>
#include <gdbm.h>

int 
main(){
	GDBM_FILE dbf;
	datum key ={"testkey",7};
	datum value ={"testvalue",9};
	
	printf("把内容保存在数据库文件中");
	dbf=gdbm_open("dbtest",0,GDBM_NEWDB,0644,0);
	gdbm_store(dbf,key,value,GDBM_INSERT);
	gdbm_close(dbf);
	printf("done. \n");


	return 0;
}
