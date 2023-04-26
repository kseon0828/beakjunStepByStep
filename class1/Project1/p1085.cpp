#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int x, y, w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	int dis_x = abs(min(w - x, x-0));
	int dis_y = abs(min(h - y, y-0));

	printf("%d", min(dis_x, dis_y));
}