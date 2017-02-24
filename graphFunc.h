#define DIRECT      0           // �ܹ���
#define UNDIRECT    1           // �����

typedef struct _edge {  // ����
    int weight;     // ����ġ
    struct _vertex *pVer;  // ����� ��
    struct _edge *pNext;
}edge;

typedef struct _vertex { // ����
    char name;  // ���� �̸�
    int deg;    // ���
    struct _edge *pEdge;    // ����
    struct _vertex *pNext;
}vertex;

typedef struct _graph { // �׷��� ���
    int v_num;  // ���� ����
    vertex *pVHead;  // ����
}graph;

/* �׷��� ������
/-- graph ------------------------------------------------------
| v_num
| *pVHead  ->/==== vertex ====\  /->/===== edge =====\  /-> edge
|           | name           |  |  | weight         |  |
|           | deg            |  |  | vertex *pVer   |  |
|           | edge *pEdge ---|--/  | edge *pNext  --|--/
|       /---|-vertex *pNext  |     \================/
|       |   \================/
|       |
|       \-->/==== vertex ====\  /->/===== edge =====\  /-> edge
|           | name           |  |  | weight         |  |
*/

vertex* getVertexAddr(graph *G, const char Name);
void newVertexToGraph(graph *G, const char Name);
void insertEdge(vertex *from, vertex *to, int weight, int mod);
