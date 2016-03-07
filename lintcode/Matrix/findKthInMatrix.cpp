class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        int m = matrix.size();
        int n = matrix[0].size();

        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int,pair<int,int> > > > q;
        // priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int,int> > > , greater<pair<int,pair<int,int>> >> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push(make_pair(matrix[0][0], make_pair(0,0)));
        visited[0][0] = true;

        while(k--){
            pair<int, pair<int, int> > t = q.top();
            if (k == 0) {
                return t.first;
            }
            q.pop();
            if (t.second.first+1 < m && visited[t.second.first+1][t.second.second] == false) {
                visited[t.second.first+1][t.second.second] = true;
                q.push(make_pair(matrix[t.second.first+1][t.second.second], make_pair(t.second.first+1, t.second.second)));
            }

            if (t.second.second+1 < n && visited[t.second.first][t.second.second+1] == false) {
                visited[t.second.first][t.second.second+1] = true;
                q.push(make_pair(matrix[t.second.first][t.second.second+1], make_pair(t.second.first, t.second.second+1)));
            }
        }
        return 0;
    }
};

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int>> >> q;
        map<pair<int,int>,bool> visited;
        q.push(make_pair(matrix[0][0],make_pair(0,0)));
        visited[make_pair(0,0)]=true;
        while(k--)
        {
            pair<int,pair<int,int> > cur = q.top();
            if(k==0)
                return cur.first;
            q.pop();
            if(cur.second.first+1<n&&visited[make_pair(cur.second.first+1,cur.second.second)]==false)
            {
                q.push(make_pair(matrix[cur.second.first+1][cur.second.second],make_pair(cur.second.first+1,cur.second.second)));
                visited[make_pair(cur.second.first+1,cur.second.second)]=true;
            }
            if(cur.second.second+1<m&&visited[make_pair(cur.second.first,cur.second.second+1)]==false)
            {
                q.push(make_pair(matrix[cur.second.first][cur.second.second+1],make_pair(cur.second.first,cur.second.second+1)));
                visited[make_pair(cur.second.first,cur.second.second+1)]=true;
            }
        }
    }
};
