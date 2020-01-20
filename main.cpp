#include "Boot.h"
using namespace Boot;

int main(int argc, char* argv[]) {
    Main* m = new Main();
    if (argc < 2) {
        m->main(12347);
    } else {
        m->main(atoi(argv[1]));
    }
  cout << "main" << endl;
    return 0;
}
