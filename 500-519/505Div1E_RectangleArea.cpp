#include <bits/stdc++.h>
using namespace std;

class RectangleArea {
public:
    int h,w;
    int board[51][51];
    int ret=0;
    // (sy,sx)を1頂点とした長方形について、穴埋め
    void greed(int sy,int sx){
        // 対角の座標で探索
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                // 長方形でないので×
                if(sy==y||sx==x) continue;
                // 3つの小長方形の面積がわかっている
                if(board[sy][sx]+board[y][sx]+board[sy][x]+board[y][x]==3){
                    if(board[y][sx]==0){
                        board[y][sx]=1;
                        greed(y,sx);
                    }
                    if(board[sy][x]==0){
                        board[sy][x]=1;
                        greed(sy,x);
                    }
                    if(board[y][x]==0){
                        board[y][x]=1;
                        greed(y,x);
                    }
                }
            }
        }
    }

    int minimumQueries( vector <string> known ){
        h=known.size();
        w=known[0].size();
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                if(known[y][x]=='Y') board[y][x]=1;
                else board[y][x]=0;
            }
        }
        // 面積がわかっているところを先に埋める
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                if(board[y][x]==1){
                    greed(y,x);
                }
            }
        }
        // 質問しないといけないので実行する度に回数+1
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                if(board[y][x]==0){
                    board[y][x]=1;
                    ret++;
                    greed(y,x);
                }
            }
        }
        return ret;
    }
};
