/**************************************************************************
考察的其实是有向图的遍历，图的遍历分为深度优先遍历和广度优先遍历，深度优先遍历用堆栈实现，
广度优先遍历用队列实现，在该题目中给出了每个节点的子节点，所以最好用广度优先遍历。
图的广度优先遍历和树的层次遍历类似，但是不是完全相同，因为图是连通的，
所以我们必须去标志那个节点被访问过，那个节点没有被访问过，最后如果全部访问完以后，
还没有找到a到b的路径，则返回false。
注意知识点：
（1）图中有环，记得标记是否被访问
（2）要分别检测两个方向（a->b，b->a） 
***************************************************************************/
/*
struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};*/

class Path {
public:
    
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) 
    {
        // write code here
       return checkPath1(b,a)||checkPath1(a,b);
    }
private:
    bool checkPath1(UndirectedGraphNode* a, UndirectedGraphNode* b) 
    {
        // write code here
       if(a == NULL && b == NULL)
           return false;
        if(a == b)
            return true;
        map<UndirectedGraphNode*,bool> map1;
        queue<UndirectedGraphNode*> que;
        que.push(a);
        while(!que.empty())
        {
            UndirectedGraphNode* ptr = que.front();
            map1[ptr] = true;
            for(int i = 0; i < ptr->neighbors.size();++i)
        	{
            	if(ptr->neighbors[i]==b)
                    return true;
                if(map1[ptr->neighbors[i]]!=true)
                    que.push(ptr->neighbors[i]);
        	}
            que.pop();
        }
        return false;
    }
};
