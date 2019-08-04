#ifndef UPDATEPROC_H_
#define UPDATEPROC_H_

#include <winsock2.h>
#include <Windows.h>

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

#include <curl/curl.h>

#include "Crypto.h"

using namespace std;

typedef void *ExitCode;

const int EVT_ID_UPDATE_PROC_ENTER_PHASE = 100000;
const int EVT_ID_UPDATE_PROC_GOT_DOWNLOADS_COUNT = 100001;
const int EVT_ID_UPDATE_PROC_NEXT_FILE = 100002;
const int EVT_ID_UPDATE_PROC_FINISHED = 100003;

class UpdateProc {
public:
	UpdateProc(string targetDir);

private:
	ofstream *m_log;
	CURL *m_curl;
	Crypto *m_crypto;

	void makeListfile(string dir, vector<string> &lines);

	struct requestFile_return {
		CURLcode retCode;
		string *data;
	};

	typedef requestFile_return requestFile_return;

	requestFile_return requestFile(string host, string remotePath, string *target);
	requestFile_return requestFile(string host, string remotePath, string targetDir);
};

#endif /* UPDATEPROC_H_ */
