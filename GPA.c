//������ �Է��ϸ� GPA�� ��µǵ��� �ϴ� ���α׷� �ۼ� 
// A+ A B+ B C+ C- D+ D F
#include <stdio.h>

int main()
{	
	int score;
	while(1)
 {
	printf("\n=====��������=====\n\n");
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &score);
	
	if(score == 100)
		printf("\n���� : A+\n");
	else if(score >= 95 && score < 100)
		printf("\n���� : A\n");
	else if(score >= 90 && score < 95)
		printf("\n���� : B+\n");	
	else if(score >= 85 && score < 90)
		printf("\n���� : B\n");
	else if(score >= 80 && score < 85)
		printf("\n���� : C+\n");
	else if(score >= 75 && score < 80)
		printf("\n���� : C\n");	
	else if(score >= 70 && score < 75)
		printf("\n���� : C-\n");
	else if(score >= 65 && score < 70)
		printf("\n���� : D+\n");
	else if(score >= 60 && score < 65)
		printf("\n���� : D\n");
	else 
		printf("\n���� : F\n");
					
 }

	return 0;	
} 
