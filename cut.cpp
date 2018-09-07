#include</usr/local/include/opencv2/opencv.hpp>
#include</usr/local/include/opencv2/highgui/highgui.hpp>
#include</usr/local/include/opencv2/core/core.hpp>
#include<iostream>
using namespace std;
using namespace cv;

Mat img;
Rect m_select;

void SplitString(const string& s, vector<string>& v, const string& c)
{
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
         
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}
int main()
{
  String path = "/home/zc/GCC/img_cut/result/0_202;323;89;40_68742.jpg";
  vector<string> v;
  vector<string> v1;
  int x;
  int y;
  int w;
  int h;
  SplitString(path, v, "_");
  String locate = v[2];
  SplitString(locate, v1, ";");
  x = atoi(v1[0].c_str());
  y = atoi(v1[1].c_str());
  w = atoi(v1[2].c_str());
  h = atoi(v1[3].c_str());
  cout<<locate<<endl;
  //cout<<x<<endl;
  //cout<<y<<endl;
  //cout<<w<<endl;
  //cout<<h<<endl;
  img = imread(path);
  imshow("source p", img);
  
  m_select = Rect(x,y,w,h);
  Mat ROI = img(m_select);
  imwrite("cut_p.jpg", ROI);
  waitKey(0);
  return 0;
}
