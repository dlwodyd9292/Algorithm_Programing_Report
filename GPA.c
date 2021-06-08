//성적을 입력하면 GPA가 출력되도록 하는 프로그램 작성 
// A+ A B+ B C+ C- D+ D F
#include <stdio.h>

int main()
{	
	int score;
	while(1)
 {
	printf("\n=====성적계산기=====\n\n");
	printf("성적을 입력하세요 : ");
	scanf("%d", &score);
	
	if(score == 100)
		printf("\n학점 : A+\n");
	else if(score >= 95 && score < 100)
		printf("\n학점 : A\n");
	else if(score >= 90 && score < 95)
		printf("\n학점 : B+\n");	
	else if(score >= 85 && score < 90)
		printf("\n학점 : B\n");
	else if(score >= 80 && score < 85)
		printf("\n학점 : C+\n");
	else if(score >= 75 && score < 80)
		printf("\n학점 : C\n");	
	else if(score >= 70 && score < 75)
		printf("\n학점 : C-\n");
	else if(score >= 65 && score < 70)
		printf("\n학점 : D+\n");
	else if(score >= 60 && score < 65)
		printf("\n학점 : D\n");
	else 
		printf("\n학점 : F\n");
					
 }

	return 0;	
} 
