#include <stdio.h>
#include <unistd.h>
#include "../checkdate.h"

#define SL2 sleep(2)

int main(void){
	int i;
	printf("This Program may test checkdate.c whether is worked.\n");

	SL2;
	printf( "\tNow Test 'Checkleapyear()'\n"
		"\tyou can see 2012 is 1, 2011 is 0\n"
		"\tTest 2012: ");
	printf("%d",Checkleapyear(2012));
	printf("\n\tTest 2011: ");
	printf("%d",Checkleapyear(2011));
	printf("\nTest Complete!\n");
	
	SL2;
	printf("\tNow Test 'Checkyear()'\n"
		"\tyou can see -112 is -1, 89 is 191, 13 is 201, 2113 is 0, 2012 is 1\n"
		"\tTest -112: %d\n\tTest 89: %d\n\tTest 13: %d\n\tTest 2113: %d\n\tTest 2012: %d\n" \
		,Checkyear(-112),Checkyear(89),Checkyear(13),Checkyear(2113),Checkyear(2012));
	printf("Test Complete!\n");

	SL2;
	printf("\tNow Test 'Checkmonth()'\n"
		"\tyou can see 0 is 0, 1 is 1, 12 is 1, 13 is 0\n"
		"\tTest 0: %d\n\tTest 1: %d\n\tTest 12: %d\n\tTest 13: %d\n" \
		,Checkmonth(0),Checkmonth(1),Checkmonth(12),Checkmonth(13));
	printf("Test Complete!\n");

	SL2;
	printf("\tNow Test 'Dayinmonth()'\n"
	"\tyou can see year of 2013, each month has the days and 2012 leap year has 29 in Feb\n");
	for(i=0;i<14;i++){
		printf("This is %d month you can see %d\n",i,Dayinmonth(i,2013));
		usleep(500000);
	}
	printf("This is 2 month in 2012 you can see %d\n\tTest Complete!\n",Dayinmonth(2,2012));

	SL2;
	printf("\tNow Test 'Checkday()'\n"
	"\tyou can see 2012-02-29 is legeled(1), 2013-02-29 is illegeled(0)\n"
	"\tTest 2012-02-29: %d\n\tTest 2013-02-29: %d\nTest Complete!\nExitting...\n" \
	,Checkday(29,2,2012),Checkday(29,2,2013));

	return 0;
}

