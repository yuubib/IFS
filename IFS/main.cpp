#include"IFS.h"
int main()
{
	IFS test("../fern.txt");
	Image img(200, 200);
	test.render(img, 1000, 30);
	img.SaveTGA("../fern.tga");
	return 0;
}