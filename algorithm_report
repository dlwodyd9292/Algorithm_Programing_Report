#include <stdio.h>  // printf, fopen_s, fgets, fclose 함수를 사용하기 위해!
#include <stdlib.h> // atoi 함수를 사용하기 위해!
#include <math.h> // 수학 관련 함수 
 
#define MAX_COUNT     100   // 관리할 최대 학생 수!
#define MAX_NAME_LEN  16    // 이름의 최대 길이
 
typedef struct StudentData  // 학생 1명의 정보를 저장할 구조체 선언
{
    int num;  // 학번
    char name[MAX_NAME_LEN];  // 이름
    unsigned int kor, eng, math; 
 	unsigned int sci, eth;
	unsigned int total, avg, rank; // 국어, 영어, 수학, 과학, 윤리, 총점, 평균, 석차 
} S_DATA;
 
float variane, stdev;
 
// ap_src_str 문자열에서 a_delimiter 또는 NULL 문자가 나올때까지 ap_buffer 메모리에
// 문자열을 복사한다. 예를들어, ap_src_str에 "abc,def"라고 들어있고 a_delimiter에
// ','가 전달되면 ap_buffer에는 "abc"문자열이 저장된다.
// 그리고 이 함수는 자신이 탐색을 완료한 위치의 주소를 반환한다. 위 예시에 적용하면
// "abc,def" 문자열의 ','문자가 위치한 주소를 반환한다.
char *GetNextString(char *ap_src_str, char a_delimiter, char *ap_buffer)
{
    // NULL 문자 또는 a_delimiter 문자가 나올때까지 반복하면서 
    // ap_src_str이 가리키는 문자를 ap_buffer가 가리키는 메모리에 복사한다.
    while (*ap_src_str && *ap_src_str != a_delimiter) *ap_buffer++ = *ap_src_str++;
 
    // 마지막 위치에 있는 문자가 줄바꿈 문자이면 줄바꿈 문자 대신 NULL 문자를 추가한다.
    // 줄바꿈 문자가 아니라면 문자열의 끝에 NULL 문자를 추가한다.
    if (*(ap_buffer - 1) == '\n') *(ap_buffer - 1) = 0;
    else *ap_buffer = 0;
 
    // ap_src_str 포인터가 가리키는 위치는 문자열 분리에 사용된 a_delimiter 문자의
    // 위치이거나 NULL 문자의 위치입니다. 만약 a_delimiter 문자 위치를 가리킨다면
    // 다음 문자는 ',' 다음 위치에서 진행될 것이기 때문에 건너띈다.
    if (*ap_src_str == a_delimiter) ap_src_str++;
 
    // 탐색을 완료한 위치의 주소를 반환한다.
    return ap_src_str;
}
 
// 파일에서 학생 정보를 읽어서 S_DATA로 선언된 배열에 저장한다.
int ReadData(const char *ap_file_name, S_DATA *ap_data, unsigned int *ap_data_count)
{
    // 읽어들인 데이터의 갯수를 계산하기 위해 시작 주소를 저장한다.
    S_DATA *p_start = ap_data;
 
    FILE *p_file = NULL;  // 파일을 열어서 사용할 파일 포인터!
    // fopen_s 함수를 사용하여 파일을 텍스트 형식의 읽기 모드로 연다!
    // 이 함수는 파일 열기에 성공했다면 0을 반환한다.
    if (0 == fopen_s(&p_file, ap_file_name, "rt")) 
	{
        // 파일에서 한 줄의 정보를 읽어서 저장할 변수와 
        // 쉼표를 기준으로 분리한 문자열을 저장할 변수
        char one_line_string[1024], str[512], *p_pos;
        // 파일에서 한 줄의 데이터를 읽는다. 
        // 하지만 첫 줄은 타이틀 정보라서 처리하지 않고 넘어간다.
        if (NULL != fgets(one_line_string, 1024, p_file)) 
		{
            // 파일의 끝까지 학생별 성적 정보를 읽어들인다.
            while (NULL != fgets(one_line_string, 128, p_file)) 
			{
                p_pos = GetNextString(one_line_string, ',', str); // 학번을 읽는다.
                ap_data->num = atoi(str);  // 학번은 정수로 저장한다.
                p_pos = GetNextString(p_pos, ',', ap_data->name); // 이름을 읽는다.
                p_pos = GetNextString(p_pos, ',', str); // 국어 점수를 읽는다.
                ap_data->kor = atoi(str);  // 국어 점수는 정수로 저장한다.
                p_pos = GetNextString(p_pos, ',', str); // 영어 점수를 읽는다.
                ap_data->eng = atoi(str);  // 영어 점수는 정수로 저장한다.
                p_pos = GetNextString(p_pos, ',', str); // 수학 점수를 읽는다.
                ap_data->math = atoi(str);  // 수학 점수는 정수로 저장한다.
                 p_pos = GetNextString(p_pos, ',', str); // 과학  점수를 읽는다.
                ap_data->sci = atoi(str);  // 과학  점수는 정수로 저장한다.
                p_pos = GetNextString(p_pos, ',', str); // 윤리 점수를 읽는다.
                ap_data->eth = atoi(str);  // 윤리 점수는 정수로 저장한다.
 
                // 개인별 과목 점수를 합산한다.
                ap_data->total = ap_data->kor + ap_data->eng + ap_data->math + ap_data->sci + ap_data->eth;
                ap_data++; // 다음 저장 위치로 이동한다.
            }
            // 데이터를 저장한 배열의 시작 주소를 입력이 진행된 주소에 빼면 
            // 입력된 데이터의 개수를 얻을 수 있다.
            *ap_data_count = ap_data - p_start;
        }
        fclose(p_file);  // 파일을 닫는다.
        return 1;  // 파일에서 정보 읽기 성공
    }
    return 0;  // 파일에서 정보 읽기 실패
}
 
// 읽어들인 학생 성적을 모두 출력한다.
void ShowData(S_DATA *ap_data, unsigned int a_count)
{
    printf("-----------------------------------------------------------------------\n");
    printf(" 학번    이름    국어  영어  수학  과학  윤리  총점   평균     석차\n");
    printf("-----------------------------------------------------------------------\n");
 
    unsigned int sum = 0; // 학급 전체 평균을 계산하기 위해
    unsigned int i = 0; 
       
	for(i = 0; i < a_count; i++, ap_data++){
        // 학생별로 성적을 출력한다.
        printf("  %-4u  %5s   %3u   %3u   %3u   %3u   %3u   %3u   %3u   %3d\n", 
            ap_data->num, ap_data->name, ap_data->kor, ap_data->eng, ap_data->math, 
            ap_data->sci, ap_data->eth, ap_data->total, ((ap_data->total)/5), ap_data->rank);
        sum += ap_data->total; // 학생의 총점을 합산한다.
    }
    printf("-----------------------------------------------------------------------\n");
    printf("				분산 : %f  표준편차 : %f\n", variane, stdev);
    printf("-----------------------------------------------------------------------\n");
    // 읽어들인 정보가 1명 이상인 경우에는 인원수와 전체 평균을 출력한다.
}

void SaveData(const char *ap_file_name, S_DATA *ap_data, unsigned int a_count)
{
    FILE *p_file = NULL;  // 파일을 열어서 사용할 파일 포인터!
    // fopen_s 함수를 사용하여 파일을 텍스트 형식의 쓰기 모드로 연다!
    // 이 함수는 파일 열기에 성공했다면 0을 반환한다.
    if (0 == fopen_s(&p_file, ap_file_name, "wt")) {
        // 첫 줄에 타이틀 정보를 저장한다.
        fprintf(p_file, "학번,성명,국어,영어,수학,과학,윤리,총점,평균,석차\n");
        // 학생의 수만큼 정보를 저장한다.
        unsigned int i = 0;
        for (i = 0; i < a_count; i++, ap_data++) {
            fprintf(p_file, "%-4d,%5s,%3u,%3u,%3u,%3u,%3u,%3u,%3u,%3u\n", ap_data->num, ap_data->name, 
        ap_data->kor, ap_data->eng, ap_data->math, ap_data->sci, ap_data->eth, ap_data->total,
		((ap_data->total)/5), ap_data->rank);
        }
    	fprintf(p_file, "-----------------------------------------------------------------------------------------------------------------------------\n");
    	fprintf(p_file, "				분산 : %f  표준편차 : %f\n", variane, stdev);
      	fprintf(p_file, "-----------------------------------------------------------------------------------------------------------------------------\n");
      	
		printf("%s 파일에 데이터를 저장했습니다!\n", ap_file_name);
        fclose(p_file);  // 파일을 닫는다.
    }
}
 
int main()
{
    S_DATA data[MAX_COUNT];  // 학생 정보를 저장할 배열을 선언
    // 학생 수와, 선택된 기능을 저장할 변수 선언
    unsigned int data_count = 0, select = 0;  
 
    // 'data.csv' 파일에서 학생 정보를 읽어 들인다.
    if (ReadData("sungjuk.csv", data, &data_count)) {
        // 사용자가 4를 입력할 때까지 계속 반복한다.
        while (select != 3) {
            printf("\n\n==========[  메뉴  ]==========\n"); // 메뉴를 출력한다.
            printf("1.sungjuk.csv 파일 열기\n");
            printf("2.Trans.csv에 저장\n");
            printf("3.프로그램 종료\n");
 
            printf("선택 : ");
            // 잘못된 입력에 대해서 체크한다.
            if (1 == scanf_s("%u", &select)) {
                printf("\n\n");
                // 기능별로 함수를 호출한다.
                if (select == 1) ShowData(data, data_count);  // 성적 보기
                else if (select == 2) SaveData("Trans.csv", data, data_count); // 저장               
            } else {
                // 잘못된 입력은 오류 메시지 출력 후에 표준입력 버퍼를 비운다.
                printf("\n잘못된 값을 입력했습니다. 다시 입력하세요.\n\n");
                rewind(stdin);
            }
        }
    } else {
        printf("sungjuk.csv 파일을 열수 없습니다. 파일 경로를 확인하세요!!\n");
    }
    return 0;
}
