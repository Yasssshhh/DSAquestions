#include<iostream>
#include <string>
using namespace std;

template <typename V>
class MapNode {
	public:
		string key;
		V value;
		MapNode* next;

		MapNode(string key, V value) {
			this->key = key;
			this->value = value;
			next = NULL;
		}

		~MapNode() {
			delete next;  //Recursive destructor.
		}
};

template <typename V>
class ourmap {
	MapNode<V>** buckets;  //A 2d bucket array to store head pointers of LL corresponding to each index.
	int count;             //To store size.
	int numBuckets;        //To store no of buckets for compression function.

	public:
	ourmap() {
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<V>*[numBuckets];
		for (int i = 0; i < numBuckets; i++) {
			buckets[i] = NULL;
		}
	}

	~ourmap() {
		for (int i = 0; i < numBuckets; i++) {
			delete buckets[i];
		}
		delete [] buckets;
	}

	int size() {
		return count;
	}

	V getValue(string key) {
		
	}

	private:
	int getBucketIndex(string key) {
		int hashCode = 0;

		int currentCoeff = 1;
		for (int i = key.length() - 1; i >= 0; i--) {
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % numBuckets;
			currentCoeff *= 37;
			currentCoeff = currentCoeff % numBuckets;
		}

		return hashCode % numBuckets;
	}

	public:
	void insert(string key, V value) {
		int bucketIndex = getBucketIndex(string key);
		MapNode<V>* head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) {
				head->value = value; //if key is present ,just increase the value.
				return;
			}
			head = head->next;
		}
        
        //if head is not found ,create a newnode ans insert that node before head so making it as head and making bucket index to this node as new head. 
		head = buckets[bucketIndex];
		MapNode<V>* node = new MapNode<V>(key, value);
		node->next = head;
		buckets[bucketIndex] = node;
		count++;

        double loadFactor=(1.0*count)/numBuckets;
        if(loadFactor>0.7){
            rehash();
        }
	}

     void rehash(){
         MapNode<V>**temp=buckets;
         buckets=new MapNode<v>*[2*numBuckets];
         for(int i=0;i<2*numBuckets;i++){
             buckets[i]=NULL;
         }
         int oldbucketcount=numBuckets;
         numBuckets*=2;
         count=0;

         for(int i=0;i<oldbucketcount;i++){
         MapNode<V>*head=temp[i];
         while (head!=NULL)
         {
            string->key=head->key;
            V value=head->value;
            insert(key,value);
            head=head->next;
         }
         }
         for(int i=0;i<oldbucketcount;i++){
             MapNode<V>*head=temp[i];
             delete head;
         }
         delete[] temp;
     }
     
};
