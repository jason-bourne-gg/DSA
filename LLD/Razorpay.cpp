#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

class Document
{
private:
    int docId;
    string content;

public:
    string getContent()
    {
        return content;
    }

    int getDocId()
    {
        return docId;
    }

    void storeContent(int id, string data)
    {
        docId = id;
        content = data;
        return;
    }
};

class Dataset
{
private:
    unordered_map<int, Document> dataset;

public:
    Dataset() : dataset() {}

    vector<string> getAllDocs()
    {
        vector<string> resultSet;
        for (auto it : dataset)
        {
            string temp = it.second.getContent();
            resultSet.push_back(temp);
        }
        return resultSet;
    }

    string storeDocument(int id, string data)
    {
        if (dataset.count(id) > 0)
        {
            return "Document ID already exist";
        }

        Document tempDoc;
        tempDoc.storeContent(id, data);

        // if not then sore in dataset
        dataset[id] = tempDoc;
        return "Document stored successfully";
    }
};

class SearchHandler
{
private:
    unordered_map<string, set<int>> search_space;

public:
    void indexDoc(Document &doc)
    {
        stringstream ss(doc.getContent());
        vector<string> v;
        string temp;
        while (ss >> temp)
        {
            v.push_back(temp);
        }

        for (auto it : v)
        {
            if (search_space.count(it) > 0)
                search_space[it].insert(doc.getDocId());
            else
                search_space[it].insert(doc.getDocId());
        }

        return;
    }

    set<int> searchDoc(string searchStr)
    {
        stringstream ss(searchStr);
        vector<string> v;
        string temp;
        while (ss >> temp)
        {
            v.push_back(temp);
        }

        set<int> result = search_space[v[0]];

        // if set result  = 0 return from here itself

        for (auto it : v)
        {
            if (search_space.count(it) > 0)
            {
                set_intersection(result.begin(), result.end(), search_space[it].begin(),
                                 search_space[it].end(),
                                 inserter(result, result.begin()));
            }
        }

        return result;
    }
};

int main()
{
    string doc1, doc2, doc3, searchString;

    Dataset dataset;
    SearchHandler search;
    cout << " Enter the dcocument 1" << endl;
    cin >> doc1;

    cout << " Enter the dcocument 2" << endl;
    cin >> doc2;

    cout << " Enter the dcocument 3" << endl;
    cin >> doc3;

    dataset.storeDocument(3, doc3);
    search.indexDoc();
    dataset.storeDocument(1, doc1);
    dataset.storeDocument(2, doc2);

    cout << " Enter the search string :" << endl;
    cin >> searchString;

    set<int> s = search.searchDoc(searchString);

    for (auto it : s)
    {
        cout << it << endl;
    }

    return 0;
};
