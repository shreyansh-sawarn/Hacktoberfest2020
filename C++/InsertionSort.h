#define INSERTIONSORT_H
#include <vector>

using namespace std;

template<typename T>
class InsertionSort {
  public:
    /*
    LOOP INVARIANT: A[0...j] is sorted
    */
    static void sort(vector<T> &array, bool ascending = true)
    {
      for(int j = 1; j < array.size(); j++)
      {
        T key = array[j];
        int i = j - 1;

        if(ascending)
          while(i >= 0 && array[i] > key)
          {
            array[i+1] = array[i];
            i--;
          }
        else
          while(i >= 0 && array[i] < key)
          {
            array[i+1] = array[i];
            i--;
          }
        array[i + 1] = key;
      }
    }
  private:

};
