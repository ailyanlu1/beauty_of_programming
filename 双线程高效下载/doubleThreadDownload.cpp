//---------------------API------------------------------
// ����Ĵ���ֻ��ʾ����룬�޷���ͨ

//downloads a block from Internet sequentially in each call
//return true, if the entire file is downloaded, otherwise false.
bool GetBlockFromNet(Block* out_block);

//writes a block to hard disk
bool WriteBlockToDisk(Block* in_block);

class Thread
{
public:
	Thread(void (*work_func)());
	~Thread();
	void Start();
	void Abort();
};

class Semaphore
{
public:
	Semaphore(int count,int max_count);
	~Semaphore();
	void Unsignal();
	void Signal();
};

class Mutex
{
public:
	WaitMutex();
	ReleaseMutex();
};
//----------------------------------------------------



//1.ȷ��ʹ���ź��������ǻ���������֤���в���
//2.����������������������û����ʱ�������߳�����
//3.�������������ղ�������û����ʱ���洢�߳�����


#define MAX_COUNT 1000
//���������飬ģ��ѭ������
Block g_Buffer[MAX_COUNT];
Thread g_Download(ProcA);
Thread g_Write(ProcB);

//һ��ʼ�������ռ�ΪMAX_COUNT�������������ɹ����ص��������
Semaphore ForDownload(MAX_COUNT,MAX_COUNT);
//һ��ʼ�����������ݿɹ��洢
Semaphore ForWrite(0,MAX_COUNT);

//���������Ƿ����
bool isDone;
//���ص����ݴӻ��������ĸ��ط���ʼ���
int in_index;
//�洢�����ݴӻ��������ĸ��ط���ʼ��ȡ
int out_index;

void ProcA()
{
	while(true)
	{
		//����ȡ��һ�����пռ䣬�Ա������������
		ForDownload.Unsignal();
		//���
		isDone=GetBlockFromNet(g_Buffer+in_index);
		//��������
		in_index=(in_index+1)%MAX_COUNT;
		//��ʾ�洢�߳̿��Թ���
		ForWrite.Signal();

		//������ȫ��������ɣ����̾Ϳ��Խ�����
		if(isDone)
			break;
	}
}

void ProcB()
{
	while(true)
	{
		//��ѯʱ�������ݿɹ��洢
		ForWrite.Unsignal();
		//�洢
		WriteBlockToDisk(g_Buffer+out_index);
		//��������
		out_index=(out_index+1)%MAX_COUNT;
		//�����пռ仹��������
		ForDownload.Signal();

		//������ȫ��������ɣ��������е����ݶ��洢��Ӳ���У����̲ſ��Խ���
		if(isDone&&in_index==out_index)
			break;
	}
}

int main()
{
	isDone=false;
	in_index=0;
	out_index=0;
	g_Download.Start();
	g_Write.Start();
}