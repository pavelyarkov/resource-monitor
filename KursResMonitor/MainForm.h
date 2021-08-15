#pragma once
#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <iphlpapi.h>
//using namespace std;
#define DIV 1024/1024
#define DIVKB 1024

#pragma comment(lib, "ws2_32.lib")
namespace KursResMonitor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tControl;
	protected:

	private: System::Windows::Forms::TabPage^  tpCPU;
	private: System::Windows::Forms::TabPage^  tpMem;

	protected:

	protected:

	protected:



	private: System::Windows::Forms::TabPage^  tpNet;
	private: System::Windows::Forms::DataGridView^  dgCPU;
	private: System::Windows::Forms::Label^  lMemPercent;
	private: System::Windows::Forms::Label^  lPhysBusy;
	private: System::Windows::Forms::Label^  lPhysFree;
	private: System::Windows::Forms::Label^  lPhysTotal;




	private: System::Windows::Forms::DataGridView^  dgMem;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  mName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  mID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  mVirt;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  mPhys;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::DataGridView^  dgNet;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nLocAdr;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nLocPort;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nRemAdr;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nRemPort;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  cName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  cID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  cThreads;
	private: System::Windows::Forms::Label^  lCPUNum;



	private: System::ComponentModel::IContainer^  components;








	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tControl = (gcnew System::Windows::Forms::TabControl());
			this->tpCPU = (gcnew System::Windows::Forms::TabPage());
			this->dgCPU = (gcnew System::Windows::Forms::DataGridView());
			this->cName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cThreads = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tpMem = (gcnew System::Windows::Forms::TabPage());
			this->dgMem = (gcnew System::Windows::Forms::DataGridView());
			this->mName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->mID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->mVirt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->mPhys = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lPhysFree = (gcnew System::Windows::Forms::Label());
			this->lPhysTotal = (gcnew System::Windows::Forms::Label());
			this->lPhysBusy = (gcnew System::Windows::Forms::Label());
			this->lMemPercent = (gcnew System::Windows::Forms::Label());
			this->tpNet = (gcnew System::Windows::Forms::TabPage());
			this->dgNet = (gcnew System::Windows::Forms::DataGridView());
			this->nName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nLocAdr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nLocPort = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nRemAdr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nRemPort = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lCPUNum = (gcnew System::Windows::Forms::Label());
			this->tControl->SuspendLayout();
			this->tpCPU->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgCPU))->BeginInit();
			this->tpMem->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgMem))->BeginInit();
			this->tpNet->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgNet))->BeginInit();
			this->SuspendLayout();
			// 
			// tControl
			// 
			this->tControl->Controls->Add(this->tpCPU);
			this->tControl->Controls->Add(this->tpMem);
			this->tControl->Controls->Add(this->tpNet);
			this->tControl->Location = System::Drawing::Point(0, 1);
			this->tControl->Name = L"tControl";
			this->tControl->SelectedIndex = 0;
			this->tControl->Size = System::Drawing::Size(793, 585);
			this->tControl->TabIndex = 0;
			// 
			// tpCPU
			// 
			this->tpCPU->Controls->Add(this->lCPUNum);
			this->tpCPU->Controls->Add(this->dgCPU);
			this->tpCPU->Location = System::Drawing::Point(4, 22);
			this->tpCPU->Name = L"tpCPU";
			this->tpCPU->Padding = System::Windows::Forms::Padding(3);
			this->tpCPU->Size = System::Drawing::Size(785, 559);
			this->tpCPU->TabIndex = 0;
			this->tpCPU->Text = L"ЦП";
			this->tpCPU->UseVisualStyleBackColor = true;
			// 
			// dgCPU
			// 
			this->dgCPU->AllowUserToAddRows = false;
			this->dgCPU->AllowUserToDeleteRows = false;
			this->dgCPU->AllowUserToResizeRows = false;
			this->dgCPU->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgCPU->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->cName, this->cID,
					this->cThreads
			});
			this->dgCPU->Location = System::Drawing::Point(9, 7);
			this->dgCPU->MultiSelect = false;
			this->dgCPU->Name = L"dgCPU";
			this->dgCPU->ReadOnly = true;
			this->dgCPU->RowHeadersVisible = false;
			this->dgCPU->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dgCPU->ShowCellToolTips = false;
			this->dgCPU->ShowEditingIcon = false;
			this->dgCPU->Size = System::Drawing::Size(769, 506);
			this->dgCPU->TabIndex = 0;
			this->dgCPU->TabStop = false;
			this->dgCPU->SelectionChanged += gcnew System::EventHandler(this, &MainForm::dgCPU_SelectionChanged);
			// 
			// cName
			// 
			this->cName->HeaderText = L"Название";
			this->cName->Name = L"cName";
			this->cName->ReadOnly = true;
			// 
			// cID
			// 
			this->cID->HeaderText = L"ИД процесса";
			this->cID->Name = L"cID";
			this->cID->ReadOnly = true;
			// 
			// cThreads
			// 
			this->cThreads->HeaderText = L"Потоки";
			this->cThreads->Name = L"cThreads";
			this->cThreads->ReadOnly = true;
			// 
			// tpMem
			// 
			this->tpMem->Controls->Add(this->dgMem);
			this->tpMem->Controls->Add(this->lPhysFree);
			this->tpMem->Controls->Add(this->lPhysTotal);
			this->tpMem->Controls->Add(this->lPhysBusy);
			this->tpMem->Controls->Add(this->lMemPercent);
			this->tpMem->Location = System::Drawing::Point(4, 22);
			this->tpMem->Name = L"tpMem";
			this->tpMem->Padding = System::Windows::Forms::Padding(3);
			this->tpMem->Size = System::Drawing::Size(785, 559);
			this->tpMem->TabIndex = 1;
			this->tpMem->Text = L"Память";
			this->tpMem->UseVisualStyleBackColor = true;
			// 
			// dgMem
			// 
			this->dgMem->AllowUserToAddRows = false;
			this->dgMem->AllowUserToDeleteRows = false;
			this->dgMem->AllowUserToResizeRows = false;
			this->dgMem->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgMem->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->mName, this->mID,
					this->mVirt, this->mPhys
			});
			this->dgMem->Location = System::Drawing::Point(6, 6);
			this->dgMem->MultiSelect = false;
			this->dgMem->Name = L"dgMem";
			this->dgMem->ReadOnly = true;
			this->dgMem->RowHeadersVisible = false;
			this->dgMem->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dgMem->ShowCellToolTips = false;
			this->dgMem->ShowEditingIcon = false;
			this->dgMem->Size = System::Drawing::Size(773, 404);
			this->dgMem->TabIndex = 4;
			this->dgMem->TabStop = false;
			this->dgMem->SelectionChanged += gcnew System::EventHandler(this, &MainForm::dgMem_SelectionChanged);
			// 
			// mName
			// 
			this->mName->HeaderText = L"Название";
			this->mName->Name = L"mName";
			this->mName->ReadOnly = true;
			// 
			// mID
			// 
			this->mID->HeaderText = L"ИД";
			this->mID->Name = L"mID";
			this->mID->ReadOnly = true;
			// 
			// mVirt
			// 
			this->mVirt->HeaderText = L"Вирт.память(КБ)";
			this->mVirt->Name = L"mVirt";
			this->mVirt->ReadOnly = true;
			// 
			// mPhys
			// 
			this->mPhys->HeaderText = L"Физ.память(КБ)";
			this->mPhys->Name = L"mPhys";
			this->mPhys->ReadOnly = true;
			// 
			// lPhysFree
			// 
			this->lPhysFree->AutoSize = true;
			this->lPhysFree->Location = System::Drawing::Point(9, 519);
			this->lPhysFree->Name = L"lPhysFree";
			this->lPhysFree->Size = System::Drawing::Size(35, 13);
			this->lPhysFree->TabIndex = 3;
			this->lPhysFree->Text = L"label2";
			// 
			// lPhysTotal
			// 
			this->lPhysTotal->AutoSize = true;
			this->lPhysTotal->Location = System::Drawing::Point(9, 480);
			this->lPhysTotal->Name = L"lPhysTotal";
			this->lPhysTotal->Size = System::Drawing::Size(35, 13);
			this->lPhysTotal->TabIndex = 2;
			this->lPhysTotal->Text = L"label1";
			// 
			// lPhysBusy
			// 
			this->lPhysBusy->AutoSize = true;
			this->lPhysBusy->Location = System::Drawing::Point(9, 443);
			this->lPhysBusy->Name = L"lPhysBusy";
			this->lPhysBusy->Size = System::Drawing::Size(35, 13);
			this->lPhysBusy->TabIndex = 1;
			this->lPhysBusy->Text = L"label1";
			// 
			// lMemPercent
			// 
			this->lMemPercent->AutoSize = true;
			this->lMemPercent->Location = System::Drawing::Point(9, 413);
			this->lMemPercent->Name = L"lMemPercent";
			this->lMemPercent->Size = System::Drawing::Size(35, 13);
			this->lMemPercent->TabIndex = 0;
			this->lMemPercent->Text = L"label1";
			// 
			// tpNet
			// 
			this->tpNet->Controls->Add(this->dgNet);
			this->tpNet->Location = System::Drawing::Point(4, 22);
			this->tpNet->Name = L"tpNet";
			this->tpNet->Padding = System::Windows::Forms::Padding(3);
			this->tpNet->Size = System::Drawing::Size(785, 559);
			this->tpNet->TabIndex = 2;
			this->tpNet->Text = L"Сеть";
			this->tpNet->UseVisualStyleBackColor = true;
			// 
			// dgNet
			// 
			this->dgNet->AllowUserToAddRows = false;
			this->dgNet->AllowUserToDeleteRows = false;
			this->dgNet->AllowUserToResizeRows = false;
			this->dgNet->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgNet->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->nName, this->nID,
					this->nLocAdr, this->nLocPort, this->nRemAdr, this->nRemPort
			});
			this->dgNet->Location = System::Drawing::Point(9, 7);
			this->dgNet->MultiSelect = false;
			this->dgNet->Name = L"dgNet";
			this->dgNet->ReadOnly = true;
			this->dgNet->RowHeadersVisible = false;
			this->dgNet->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dgNet->ShowEditingIcon = false;
			this->dgNet->ShowRowErrors = false;
			this->dgNet->Size = System::Drawing::Size(769, 545);
			this->dgNet->TabIndex = 0;
			this->dgNet->TabStop = false;
			this->dgNet->SelectionChanged += gcnew System::EventHandler(this, &MainForm::dgNet_SelectionChanged);
			// 
			// nName
			// 
			this->nName->HeaderText = L"Название";
			this->nName->Name = L"nName";
			this->nName->ReadOnly = true;
			// 
			// nID
			// 
			this->nID->HeaderText = L"ИД";
			this->nID->Name = L"nID";
			this->nID->ReadOnly = true;
			// 
			// nLocAdr
			// 
			this->nLocAdr->HeaderText = L"Локальный адрес";
			this->nLocAdr->Name = L"nLocAdr";
			this->nLocAdr->ReadOnly = true;
			// 
			// nLocPort
			// 
			this->nLocPort->HeaderText = L"Локальный порт";
			this->nLocPort->Name = L"nLocPort";
			this->nLocPort->ReadOnly = true;
			// 
			// nRemAdr
			// 
			this->nRemAdr->HeaderText = L"Удалённый адрес";
			this->nRemAdr->Name = L"nRemAdr";
			this->nRemAdr->ReadOnly = true;
			// 
			// nRemPort
			// 
			this->nRemPort->HeaderText = L"Удалённый порт";
			this->nRemPort->Name = L"nRemPort";
			this->nRemPort->ReadOnly = true;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 800;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// lCPUNum
			// 
			this->lCPUNum->AutoSize = true;
			this->lCPUNum->Location = System::Drawing::Point(9, 520);
			this->lCPUNum->Name = L"lCPUNum";
			this->lCPUNum->Size = System::Drawing::Size(35, 13);
			this->lCPUNum->TabIndex = 1;
			this->lCPUNum->Text = L"label1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(794, 587);
			this->Controls->Add(this->tControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Монитор ресурсов";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->tControl->ResumeLayout(false);
			this->tpCPU->ResumeLayout(false);
			this->tpCPU->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgCPU))->EndInit();
			this->tpMem->ResumeLayout(false);
			this->tpMem->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgMem))->EndInit();
			this->tpNet->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgNet))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void memcheck() {
			MEMORYSTATUSEX statex;
			statex.dwLength = sizeof(statex);
			GlobalMemoryStatusEx(&statex);
			lMemPercent->Text = "Использование физической памяти: "+ statex.dwMemoryLoad+"%";
			lPhysTotal->Text = "Всего физ.памяти: : " + statex.ullTotalPhys / DIV + "КБ";
			lPhysFree->Text = "Свободно физ.памяти: " + statex.ullAvailPhys / DIV + "КБ";
			lPhysBusy->Text = "Занято физ.памяти: " + (statex.ullTotalPhys / DIV - statex.ullAvailPhys / DIV) + "КБ";
		}
	private:
		void proclist() {
			HANDLE hSnap;
			int n=0;
			hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			if (hSnap == INVALID_HANDLE_VALUE)
			{
				return;
			}
			PROCESSENTRY32 proc;
			proc.dwSize = sizeof(PROCESSENTRY32);
			if (Process32First(hSnap, &proc))
			{
				do {
					System::String^ s=gcnew String(proc.szExeFile);
					dgCPU->Rows->Add(s, proc.th32ProcessID, proc.cntThreads);
					n++;
				} while (Process32Next(hSnap, &proc));
				CloseHandle(hSnap);
				lCPUNum->Text = "Число запущенных процессов: "+n;
			}
			else return;
		}
	private:
		void PrintMemoryInfo() {
			HANDLE hSnap;
			hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			if (hSnap == INVALID_HANDLE_VALUE)
			{
				return;
			}
			PROCESSENTRY32 proc;
			proc.dwSize = sizeof(PROCESSENTRY32);
			HANDLE hProcess;
			PROCESS_MEMORY_COUNTERS pmc;
			if (Process32First(hSnap, &proc))
			{
				do {
					hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
						PROCESS_VM_READ,
						FALSE, proc.th32ProcessID);
					if (NULL == hProcess)
						continue;
					if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
					{
						System::String^ s = gcnew String(proc.szExeFile);
						dgMem->Rows->Add(s, proc.th32ProcessID, pmc.PagefileUsage / DIVKB, pmc.WorkingSetSize / DIVKB);
					}
				} while (Process32Next(hSnap, &proc));
				CloseHandle(hSnap);
				CloseHandle(hProcess);
			}
			else return;
		}
	private:
		void netinfo() {
			DWORD(WINAPI *pGetExtendedTcpTable)(
				PVOID pTcpTable,
				PDWORD pdwSize,
				BOOL bOrder,
				ULONG ulAf,
				TCP_TABLE_CLASS TableClass,
				ULONG Reserved
				);
			MIB_TCPTABLE_OWNER_PID *pTCPInfo;
			MIB_TCPROW_OWNER_PID *owner;
			DWORD size;
			DWORD dwResult;

			HMODULE hLib = LoadLibrary(L"iphlpapi.dll");

			pGetExtendedTcpTable = (DWORD(WINAPI *)(PVOID, PDWORD, BOOL, ULONG, TCP_TABLE_CLASS, ULONG))
				GetProcAddress(hLib, "GetExtendedTcpTable");

			dwResult = pGetExtendedTcpTable(NULL, &size, true, AF_INET, TCP_TABLE_OWNER_PID_CONNECTIONS, 0);
			pTCPInfo = (MIB_TCPTABLE_OWNER_PID*)malloc(size);
			dwResult = pGetExtendedTcpTable(pTCPInfo, &size, true, AF_INET, TCP_TABLE_OWNER_PID_CONNECTIONS, 0);
			struct in_addr IpAddr;
			char szLocalAddr[128];
			char szRemoteAddr[128];

			HANDLE hSnap;
			hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			if (hSnap == INVALID_HANDLE_VALUE)
			{
				return;
			}
			PROCESSENTRY32 proc;
			proc.dwSize = sizeof(PROCESSENTRY32);
			HANDLE hProcess;
			if (Process32First(hSnap, &proc))
			{
				do {
					hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
						PROCESS_VM_READ,
						FALSE, proc.th32ProcessID);
					if (NULL == hProcess)
						continue;
					for (DWORD dwLoop = 0; dwLoop < pTCPInfo->dwNumEntries; dwLoop++)
					{
						owner = &pTCPInfo->table[dwLoop];
						if (proc.th32ProcessID == owner->dwOwningPid) {
							IpAddr.S_un.S_addr = owner->dwLocalAddr;
							strcpy_s(szLocalAddr, sizeof(szLocalAddr), inet_ntoa(IpAddr));
							IpAddr.S_un.S_addr = owner->dwRemoteAddr;
							strcpy_s(szRemoteAddr, sizeof(szRemoteAddr), inet_ntoa(IpAddr));
							System::String^ s = gcnew String(proc.szExeFile);
							System::String^ s3 = gcnew String(szLocalAddr);
							System::String^ s5 = gcnew String(szRemoteAddr);
							dgNet->Rows->Add(s, owner->dwOwningPid, s3, ntohs(owner->dwLocalPort), s5, ntohs(owner->dwRemotePort));
						}
					}
				} while (Process32Next(hSnap, &proc));
				CloseHandle(hSnap);
				CloseHandle(hProcess);
			}
			else return;
		}

	private: 
		System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
			memcheck();
			proclist();
			PrintMemoryInfo();
			netinfo();
		}
private: System::Void dgMem_SelectionChanged(System::Object^  sender, System::EventArgs^  e) {
	//Запрет установки выделений ячеек
	if (MouseButtons != System::Windows::Forms::MouseButtons::None)
		dgMem->CurrentCell->Selected = false;
	//Удаление выделения с первой ячейки
	dgMem->Rows[0]->Cells[0]->Selected = false;
}
private: System::Void dgCPU_SelectionChanged(System::Object^  sender, System::EventArgs^  e) {
	//Запрет установки выделений ячеек
	if (MouseButtons != System::Windows::Forms::MouseButtons::None)
		dgCPU->CurrentCell->Selected = false;
	//Удаление выделения с первой ячейки
	dgCPU->Rows[0]->Cells[0]->Selected = false;
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	int r = dgCPU->FirstDisplayedScrollingRowIndex;
	int k = dgMem->FirstDisplayedScrollingRowIndex;
	int j = dgNet->FirstDisplayedScrollingRowIndex;
	if (k == -1)
		k = 0;
	if (j == -1)
		j = 0;
	dgCPU->Rows->Clear();
	dgMem->Rows->Clear();
	dgNet->Rows->Clear();
	memcheck();
	proclist();
	PrintMemoryInfo();
	netinfo();
	if (dgCPU->SortOrder == SortOrder::Ascending)
		dgCPU->Sort(dgCPU->SortedColumn, ListSortDirection::Ascending);
	else if (dgCPU->SortOrder == SortOrder::Descending)
		dgCPU->Sort(dgCPU->SortedColumn, ListSortDirection::Descending);

	if (dgMem->SortOrder == SortOrder::Ascending)
		dgMem->Sort(dgMem->SortedColumn, ListSortDirection::Ascending);
	else if (dgMem->SortOrder == SortOrder::Descending)
		dgMem->Sort(dgMem->SortedColumn, ListSortDirection::Descending);

	if (dgNet->SortOrder == SortOrder::Ascending)
		dgNet->Sort(dgNet->SortedColumn, ListSortDirection::Ascending);
	else if (dgNet->SortOrder == SortOrder::Descending)
		dgNet->Sort(dgNet->SortedColumn, ListSortDirection::Descending);
	dgCPU->FirstDisplayedScrollingRowIndex = r;
	dgMem->FirstDisplayedScrollingRowIndex = k;
	dgNet->FirstDisplayedScrollingRowIndex = j;
	dgCPU->CurrentCell->Selected = false;
	dgMem->CurrentCell->Selected = false;
	dgNet->CurrentCell->Selected = false;
}
private: System::Void dgNet_SelectionChanged(System::Object^  sender, System::EventArgs^  e) {
	if (MouseButtons != System::Windows::Forms::MouseButtons::None)
		dgNet->CurrentCell->Selected = false;
	dgNet->Rows[0]->Cells[0]->Selected = false;
}
};
}
