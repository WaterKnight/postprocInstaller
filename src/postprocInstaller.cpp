#include <winsock2.h>

#include <string>
#include <windows.h>

#include "updateProc.h"

using namespace std;

string getDir2(string path) {
	size_t pos = path.rfind('/');

	if (pos != string::npos) {
		string ret = path.substr(0, pos);

		ret.append("\\");

		return ret;
	}

	pos = path.rfind('\\');

	if (pos != string::npos) {
		string ret = path.substr(0, pos);

		ret.append("\\");

		return ret;
	}

	return string();
}

string getLocalPath()
{
	char name[MAX_PATH];

	GetModuleFileNameA(NULL, name, MAX_PATH);

	string s;

	s.append(name);

	return s;
}

int main() {
	string localPath = getLocalPath();

	string localDir = getDir2(localPath);

	string targetDir = localDir;

	targetDir.append("updateTemp\\");

	UpdateProc *updateProc = new UpdateProc(targetDir);

	string updaterCmd;

	updaterCmd.append("start \"\" \"");
	updaterCmd.append(targetDir);
	updaterCmd.append("postprocUpdater.exe\" ");
	updaterCmd.append("\"");
	updaterCmd.append(localDir);
	updaterCmd.append("\\\"");

	fprintf(stdout, "%s\n", updaterCmd.c_str());
cout << updaterCmd.c_str() << '\n';
	system(updaterCmd.c_str());

	return 0;
}
