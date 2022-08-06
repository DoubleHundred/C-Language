#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

char Eng[100][100] = { 0 };		//English
char Kor[100][100] = { 0 };		//Korean

int wrd = 0;
int loop = 0;

void main() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

	printf("\"0 0\" 입력으로 단어를 그만 입력 할 수 있습니다, 띄어쓰기는 \'_\'로 입력해 주세요. \n");

	while (1) {
		wrd++;
		printf("\n\n\"Eng Kor\" 단어 입력 %d. ", wrd);
		scanf("%s %s", Eng[wrd - 1], Kor[wrd - 1]);

		if (Eng[wrd - 1][0] == '0' && Kor[wrd - 1][0] == '0') {
			wrd--;
			printf("\n입력한 단어 개수: %d, [wrdAdd] 명령어로 더 추가할 수 있습니다. \n\n", wrd);

			if (wrd == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

				printf("\n추가한 단어가 없습니다. 3초 후 자동으로 프로그램을 종료합니다. \n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				Sleep(3000);
				return;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			break;
		}
	}

	while (1) {
		char cmd[15] = { 0 };

		srand(time(NULL));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		printf("\n\"help\"를 입력하여 여러 명령어들을 볼 수 있습니다 \n> ");
		
		scanf("%s", cmd);

		/*====================*/

		/*=== 도움말 ===*/		// help = 도움말 출력
		if(strcmp(cmd, "help") == 0) {		//strcmp는 값이 참이면 '0', 거짓이면 '-1'을 출력한다. (왜 굳이..)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

			printf("\nLearn English Word Helper 1.0v 도움말 \n\n\n");
			printf("\n[단어 외우기] \n\n");
			printf("EngType1 \n영단어가 입력한 순서대로 나오며, 한국어를 입력해야 합니다. \n\nEngType2 \n영단어가 뒷 순서부터 순서대로 나오며, 한국어를 입력해야합니다. \n\nEngType3 \n영단어가 영단어 개수 x 2 만큼 랜덤으로 나옵니다. \(안 나오는 단어가 존재할 수 있음\)\n\n");
			printf("KorType1 \n한글이 입력한 순서대로 나오며, 영어를 입력해야 합니다. \n\nKorType2 \n한글이 둣 순서부터 순서대로 나오며, 영어를 입력해야 합니다. \n\nKorType3 \n한글이 한글 개수 x 2 만큼 랜덤으로 나옵니다. \(안 나오는 단어가 존재할 수 있음\) \n\n\n");
			printf("\n[단어 추가/삭제] \n\n");
			printf("wrd \n저장된 단어를 볼 수 있습니다. \n\n");
			printf("wrdAdd \n새로운 단어를 기존 단어와 함께 추가합니다. \n\nwrdDellAll \n모든 단어를 지우고 다시 저장합니다. \n\nWrdDelPrt \n원하는 단어 하나만 지웁니다. \n\n\n");
			printf("\n[종료 및 기타] \n\n");
			printf("prgmFnsh / PF \n프로그램을 종료합니다. \n\nDEL \n모든 내용을 삭제합니다. \n\nVerChk \n현재 버전을 확인 할 수 있습니다. \n\n");
			printf("mail \n제작자의 메일을 볼 수 있습니다 \n\nGitHub \n이 파일이 저장되어 있는 C-Language 레파지토리 링크가 보여집니다. \n\nLink \n제작자의 SNS 링크들을 볼 수 있습니다. \n\ncredits \n제작에 도움을 주신 분들을 볼 수 있습니다. \n\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}

		/*=== 단어 외우기 ===*/		// EngType1/KorType1 = 1 ~ N 까지의 영/한글 단어 출력, EngType2/KorType2 = EngType1과 같고, N ~ 1이 다름, EngType3/KorType3 = 앞에와 같으나 N * 2만큼 랜덤으로 영/한글단어가 나옴 (안 나오는 것 존재)
		else if(strcmp(cmd, "EngType1") == 0) {
			int crect = 0;

			system("cls");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("EngType1 단어 테스트를 시작합니다. \n");

			crect = 0;
			int wrng[100] = { 0 };
			int w = 0;

			for (int q = 0; q < wrd; q++) {
				printf("\n%d. %s: ", (q + 1), Eng[q]);

				char ans[100] = { 0 };

				scanf("%s", ans);

				if (strcmp(ans, Kor[q]) == 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					printf("correct \n");
					crect++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("wrong answer \n");
					wrng[w] = q;
					w++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				}
			}

			printf("%d문제 중 %d문제 맞았습니다. \n\n", wrd, crect);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			for (int q = 0; q < w; q++) {
				printf("%d. %s %s \n", (q + 1), Eng[wrng[q]], Kor[wrng[q]]);
			}

			printf("\n\n\n");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "EngType2") == 0) {
			int crect = 0;

			system("cls");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("EngType2 단어 테스트를 시작합니다. \n");

			crect = 0;
			int wrng[100] = { 0 };
			int w = 0;

			for (int q = (wrd - 1); q >= 0; q--) {
				printf("\n%d. %s: ", (q + 1), Eng[q]);

				char ans[100] = { 0 };

				scanf("%s", ans);

				if (strcmp(ans, Kor[q]) == 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					printf("correct \n");
					crect++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("wrong answer \n");
					wrng[w] = q;
					w++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				}
			}

			printf("%d문제 중 %d문제 맞았습니다. \n\n", wrd, crect);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			for (int q = 0; q < w; q++) {
				printf("%d. %s %s \n", (q + 1), Eng[wrng[q]], Kor[wrng[q]]);
			}

			printf("\n\n\n");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "EngType3") == 0) {
		int crect = 0;

		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("EngType3 단어 테스트를 시작합니다. \n");

		crect = 0;
		int wrng[100] = { 0 };
		int w = 0;

		for (int q = 0; q < (wrd * 2); q++) {
			int rnd = rand() % wrd;

			printf("\n%d. %s: ", (q + 1), Eng[rnd]);

			char ans[100] = { 0 };

			scanf("%s", ans);

			if (strcmp(ans, Kor[rnd]) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printf("correct \n");
				crect++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("wrong answer \n");
				wrng[w] = rnd;
				w++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
		}

		printf("%d문제 중 %d문제 맞았습니다. \n\n", (wrd * 2), crect);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		for (int q = 0; q < w; q++) {
			printf("%d. %s %s \n", (q + 1), Eng[wrng[q]], Kor[wrng[q]]);
		}

		printf("\n\n\n");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "KorType1") == 0) {
		int crect = 0;

		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("KorType1 단어 테스트를 시작합니다. \n");

		crect = 0;
		int wrng[100] = { 0 };
		int w = 0;

		for (int q = 0; q < wrd; q++) {
			printf("\n%d. %s: ", (q + 1), Kor[q]);

			char ans[100] = { 0 };

			scanf("%s", ans);

			if (strcmp(ans, Eng[q]) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printf("correct \n");
				crect++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("wrong answer \n");
				wrng[w] = q;
				w++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
		}

		printf("%d문제 중 %d문제 맞았습니다. \n\n", wrd, crect);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		for (int q = 0; q < w; q++) {
			printf("%d. %s %s \n", (q + 1), Kor[wrng[q]], Eng[wrng[q]]);
		}

		printf("\n\n\n");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "KorType2") == 0) {
		int crect = 0;

		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("KorType2 단어 테스트를 시작합니다. \n");

		crect = 0;
		int wrng[100] = { 0 };
		int w = 0;

		for (int q = (wrd - 1); q >= 0; q--) {
			printf("\n%d. %s: ", (q + 1), Kor[q]);

			char ans[100] = { 0 };

			scanf("%s", ans);

			if (strcmp(ans, Eng[q]) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printf("correct \n");
				crect++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("wrong answer \n");
				wrng[w] = q;
				w++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
		}

		printf("%d문제 중 %d문제 맞았습니다. \n\n", wrd, crect);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		for (int q = 0; q < w; q++) {
			printf("%d. %s %s \n", (q + 1), Kor[wrng[q]], Eng[wrng[q]]);
		}

		printf("\n\n\n");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "KorType3") == 0) {
		int crect = 0;

		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("KorType3 단어 테스트를 시작합니다. \n");

		crect = 0;
		int wrng[100] = { 0 };
		int w = 0;

		for (int q = 0; q < (wrd * 2); q++) {
			int rnd = rand() % wrd;

			printf("\n%d. %s: ", (q + 1), Kor[rnd]);

			char ans[100] = { 0 };

			scanf("%s", ans);

			if (strcmp(ans, Eng[rnd]) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printf("correct \n");
				crect++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("wrong answer \n");
				wrng[w] = rnd;
				w++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
		}

		printf("%d문제 중 %d문제 맞았습니다. \n\n", (wrd * 2), crect);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		for (int q = 0; q < w; q++) {
			printf("%d. %s %s \n", (q + 1), Kor[wrng[q]], Eng[wrng[q]]);
		}

		printf("\n\n\n");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}

		/*=== 단어 추가/삭제 ===*/	// wrd = 저장한 단어 보기, wrdAdd = 단어 추가, wrdDelAll = 단어 전체 삭제 및 다시 입력, wrdDelPrt = 특정 부분 단어 삭제
		else if (strcmp(cmd, "wrd") == 0) {		// no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			for (int q = 0; q < wrd; q++) {
				printf("\n%d. %s %s \n",q + 1, Eng[q], Kor[q]);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		}
	
		else if (strcmp(cmd, "wrdAdd") == 0) {		// no header

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("\n\"0 0\" 입력으로 단어를 그만 입력 할 수 있습니다, 띄어쓰기는 \'_\'로 입력해 주세요. \n");

			while (1) {
				wrd++;
				printf("\n\n\"Eng Kor\" 단어 입력 %d. ", wrd);
				scanf("%s %s", Eng[wrd - 1], Kor[wrd - 1]);

				if (Eng[wrd - 1][0] == '0' && Kor[wrd - 1][0] == '0') {
					wrd--;
					printf("\n입력한 단어 개수: %d, [wrdAdd] 명령어로 더 추가할 수 있습니다. \n\n", wrd);

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				}
			}
		}
		else if (strcmp(cmd, "wrdDelAll") == 0) {	// no header
			for (int q = 0; q < wrd; q++) {
				for (int p = 0; p < 100; p++) {
					Eng[q][p] = 0;
					Kor[q][p] = 0;
				}
			}

			wrd = 0;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

			printf("\n\"0 0\" 입력으로 단어를 그만 입력 할 수 있습니다, 띄어쓰기는 \'_\'로 입력해 주세요. \n");

			while (1) {
				wrd++;
				printf("\n\n\"Eng Kor\" 단어 입력 %d. ", wrd);
				scanf("%s %s", Eng[wrd - 1], Kor[wrd - 1]);

				if (Eng[wrd - 1][0] == '0' && Kor[wrd - 1][0] == '0') {
					wrd--;
					printf("\n입력한 단어 개수: %d, [wrdAdd] 명령어로 더 추가할 수 있습니다. \n\n", wrd);

					if (wrd == 0) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

						printf("\n추가한 단어가 없습니다. 3초 후 자동으로 프로그램을 종료합니다. \n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

						Sleep(3000);
						return;
					}

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				}
			}
		}
		else if (strcmp(cmd, "wrdDelPrt") == 0) {	// no header
			int prt = 0;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

			printf("\n삭제하고 싶은 단어의 번호를 입력해 주세요. \n> ");
			scanf("%d", &prt);

			for (int q = 0; q < 100; q++) {
				Eng[prt - 1][q] = 0;
				Kor[prt - 1][q] = 0;
			}
			wrd--;

			for (int q = prt; q <= wrd; q++) {
				for (int p = 0; p < 100; p++) {
					Eng[q - 1][p] = Eng[q][p];
					Kor[q - 1][p] = Kor[q][p];
				}
			}

			printf("\n%d번 단어를 성공적으로 삭제했습니다. \n", prt);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}

		/*=== 종료 및 기타 ===*/	// prgmFnsh = 프로그램 종료, DEL = 화면 지우기, VerChk = 버전 체크, mail = 제작자 매일, GitHub = 깃허브 C-Language 링크, Link = 제작자 SNS, credits = 제작에 도움을 주신 분들
		else if (strcmp(cmd, "prgmFnsh") == 0 || strcmp(cmd, "PF") == 0) {	// no header
			return;
		}
		else if (strcmp(cmd, "DEL") == 0) {			// no header
			system("cls");		// 콘솔 화면 초기화
		}
		else if (strcmp(cmd, "VerChk") == 0) {		// no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			printf("\nVer 1.0 \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "mail") == 0) {		// no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("\nmail: dnil4@naver.com \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "GitHub") == 0) {		// no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("\nGitHub: https://github.com/BOLLT44/C-Language \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "Link") == 0) {		// no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("\nTistory:    https://bollt.tistory.com/ \nYouTube:    https://www.youtube.com/channel/UCA-5RGnzDV2rskwBk241u3A \n");
			printf("Twitch:     https://www.twitch.tv/bollt40\nTwitter:    https://twitter.com/BOLLT44 \nDiscord:    https://discord.com/invite/35hGybhC2Y \n");
			printf("Naver Blog: https://blog.naver.com/dnil4 \nNaver Post: https://post.naver.com/my.naver?isHome=true \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "credits") == 0) {		// no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			printf("made by: BOLLT(real name X) \n");
			printf("\nThank You!!\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}

		/*=== ERROR ===*/
		else {		//no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("\n명령어를 인식하지 못했습니다. - 명령어에 오타가 있는지 확인하세요. / 존재하는 명령어인지 확인하세요. / 오류가 있으면 알려주세요. [mail] 명령어를 입력하여 제작자의 메일을 확인 할 수 있습니다.\n\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}

		/*====================*/
	}

	return;
}