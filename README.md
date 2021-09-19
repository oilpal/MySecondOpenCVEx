# MySecondOpenCVEx
Activity를 먼저 생성하고, opencv C/C++ native code를 추가한 예제

-- Android NDK + CMake + OpenCV 카메라 예제 (Native C++ 프로젝트로 생성하여 구성)
https://www.youtube.com/watch?v=oFFnyJAIJp8
https://webnautes.tistory.com/1054?category=704164

-- NDK를 이용한 애플리케이션 만들기 (CMake)  - 2016년 
https://pr0gr4m.tistory.com/entry/NDK%EB%A5%BC-%EC%9D%B4%EC%9A%A9%ED%95%9C-%EC%95%A0%ED%94%8C%EB%A6%AC%EC%BC%80%EC%9D%B4%EC%85%98-%EB%A7%8C%EB%93%A4%EA%B8%B0-CMake

-- Android Project에서 C/C++ 소스 파일 생성하는 법
https://developer.android.com/studio/projects/add-native-code.html#create-sources

새 C/C++ 소스 파일 생성
기존 프로젝트에 새 C/C++ 소스 파일을 추가하려면 다음 단계를 따르세요.

아직 앱의 기본 소스 세트에 cpp/ 디렉터리가 없다면 다음과 같이 디렉터리를 생성합니다.
IDE 왼쪽에서 Project 창을 열고 드롭다운 메뉴에서 Project 뷰를 선택합니다.
your-module > src로 이동하고 main 디렉터리를 마우스 오른쪽 버튼으로 클릭한 후 New > Directory를 선택합니다.
디렉터리 이름으로 cpp를 입력하고 OK를 클릭합니다.
cpp/ 디렉터리를 마우스 오른쪽 버튼으로 클릭하여 New > C/C++ Source File을 선택합니다.
소스 파일의 이름(예: native-lib)을 입력합니다.
Type 드롭다운 메뉴에서 소스 파일의 파일 확장자(예: .cpp)를 선택합니다.
Edit File Types 를 클릭하여 .cxx 또는 .hxx와 같은 다른 파일 형식을 드롭다운 메뉴에 추가할 수 있습니다. 팝업되는 C/C++ 대화상자의 Source Extension과 Header Extension 드롭다운 메뉴에서 다른 파일 확장자를 선택하고 OK를 클릭합니다.
헤더 파일도 생성하려면 Create an associated header 체크박스를 선택합니다.
OK를 클릭합니다.
새 C/C++ 파일을 프로젝트에 추가한 후에도 CMake를 구성하여 네이티브 라이브러리에 포함해야 합니다.

-- https://github.com/webnautes/nudapeu
https://github.com/webnautes/nudapeu/blob/master/0613-01


-- 기타
 * detectCannyEdge 소스코드
   https://brunch.co.kr/@mystoryg/76