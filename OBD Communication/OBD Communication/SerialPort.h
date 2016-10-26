#pragma once
#pragma once
#include <Windows.h>
#include <atlstr.h>
#include <iostream>
using namespace std;
#define BUFFER_SIZE 128

class CSerialPort
{
public:
	CSerialPort(void);
	virtual ~CSerialPort(void);

private:
	HANDLE  m_hComm;
	DCB     m_dcb;
	COMMTIMEOUTS m_CommTimeouts;
	bool    m_bPortReady;
	bool    m_bWriteRC;
	bool    m_bReadRC;
	DWORD   m_iBytesWritten;
	DWORD   m_iBytesRead;
	DWORD   m_dwBytesRead;

public:
	void ClosePort();
	bool readResponse(char &resp);
	bool readResponse(BYTE* &resp, UINT size);
	bool runCommand(const char *cmd, char *data, unsigned int dataLength);
	bool runCommand(byte *cmd, char *data, unsigned int dataLength);
	void getBytes(const char*mode, const char *chkMode, const char *pid, byte *values, unsigned int numValue);
	bool OpenPort(CString portname);
	bool SetCommunicationTimeouts(DWORD ReadIntervalTimeout,
		DWORD ReadTotalTimeoutMultiplier, DWORD ReadTotalTimeoutConstant,
		DWORD WriteTotalTimeoutMultiplier, DWORD WriteTotalTimeoutConstant);
	bool ConfigurePort(DWORD BaudRate, BYTE ByteSize, DWORD fParity,
		BYTE  Parity, BYTE StopBits);
};