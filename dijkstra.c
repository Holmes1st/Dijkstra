#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"


/**
 * @brief      Do Dijkstra stuff
 *
 * @param      G     Graph
 * @param      from  Source
 * @param      to    Destination
 *
 * @return     shortest length from [from] to [to]
 */
DijekstraResult DijkstraShortestPathsSingleTargetCount(graph* G, vertex* from, vertex* to) {
	// �ӽ� ����
	vertex *pVer = NULL;
	node *pDeqNode = NULL;

	// ť
	queue *Q = initQueue();


	// ��� ���� ť�� ����
	pVer = G->pVHead;
	while (pVer) {
        enqueue(Q, pVer);
		pVer = pVer->pNext;
    }

	// from �� �켱���� �ʱ�ȭ
	findNode(Q, from)->priority = 0;

	// Ž�� ����
	while (1) {	// if dequeue data == to : break
		pDeqNode = dequeue(Q);
		if (pDeqNode->pData == to || pDeqNode == NULL) break;

		pVer = pDeqNode->pData;
		edge *pEdge = pVer->pEdge;

		// ���� ��ȭ
        while (pEdge) {
			node *nodeFromEdge = findNode(Q, pEdge->pVer);
            if (nodeFromEdge) {
				if (pDeqNode->priority + pEdge->weight < nodeFromEdge->priority) {
					nodeFromEdge->priority = pDeqNode->priority + pEdge->weight;
                    pEdge->pVer->deg = (pVer->deg == 0) ? 1 : pVer->deg;
                }
                else if (pDeqNode->priority + pEdge->weight == nodeFromEdge->priority) {
                    pEdge->pVer->deg += pVer->deg;
                }
            }

			pEdge = pEdge->pNext;
        }
		free(pDeqNode);
    }


	if (pDeqNode == NULL) {
		return (DijekstraResult) { -1, -1 };
	}
	pVer = pDeqNode->pData;
	DijekstraResult result = { pVer->deg, pDeqNode->priority };

	while (pDeqNode) {
		free(pDeqNode);
		pDeqNode = dequeue(Q);
	}
	free(Q);

    return result;
}
