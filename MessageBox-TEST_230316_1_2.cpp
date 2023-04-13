#include <windows.h>

int Message() {
	return MessageBox(NULL, TEXT("\"여친\"을(를) 찾을 수 없습니다."), TEXT("Brain"), MB_RETRYCANCEL | MB_ICONERROR);
}

int main() {
	int i = MessageBox(NULL, TEXT("\"여친\"을(를) 찾으시겠습니까?"), TEXT("Brain"), MB_YESNO);

	if (i == IDNO) {
		return 0;
	}

	while (true) {
		int result = Message();

		if (result == IDRETRY) {
			continue;
		}
		else {
			break;
		}
	}


	return 0;
}
