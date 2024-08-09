#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Document
{
private:
    int docId;
    string content;

public:
    string getContent() const
    {
        return content;
    }

    int getDocId() const
    {
        return docId;
    }

    void storeContent(int id, const string &data)
    {
        docId = id;
        content = data;
    }
};

class Dataset
{
private:
    unordered_map<int, Document> dataset;

public:
    Dataset() : dataset() {}

    vector<string> getAllDocs() const
    {
        vector<string> resultSet;
        for (const auto &it : dataset)
        {
            resultSet.push_back(it.second.getContent());
        }
        return resultSet;
    }

    string storeDocument(int id, const string &data)
    {
        if (dataset.count(id) > 0)
        {
            return "Document ID already exists";
        }

        Document tempDoc;
        tempDoc.storeContent(id, data);
        dataset[id] = tempDoc;
        return "Document stored successfully";
    }

    const unordered_map<int, Document> &getDataset() const
    {
        return dataset;
    }
};

class SearchHandler
{
private:
    unordered_map<string, set<int>> search_space;

public:
    void indexDoc(const Document &doc)
    {
        stringstream ss(doc.getContent());
        vector<string> v;
        string temp;
        while (ss >> temp)
        {
            v.push_back(temp);
        }

        for (const auto &it : v)
        {
            search_space[it].insert(doc.getDocId());
        }
    }

    set<int> searchDoc(const string &searchStr) const
    {
        stringstream ss(searchStr);
        vector<string> v;
        string temp;
        while (ss >> temp)
        {
            v.push_back(temp);
        }

        if (v.empty())
            return {};

        set<int> result = search_space.count(v[0]) ? search_space.at(v[0]) : set<int>();

        for (const auto &it : v)
        {
            if (search_space.count(it) > 0)
            {
                set<int> tempSet;
                set_intersection(result.begin(), result.end(), search_space.at(it).begin(), search_space.at(it).end(),
                                 inserter(tempSet, tempSet.begin()));
                result = move(tempSet);
            }
            else
            {
                return {};
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

    cout << "Enter the document 1:" << endl;
    getline(cin, doc1);

    cout << "Enter the document 2:" << endl;
    getline(cin, doc2);

    cout << "Enter the document 3:" << endl;
    getline(cin, doc3);

    dataset.storeDocument(1, doc1);
    dataset.storeDocument(2, doc2);
    dataset.storeDocument(3, doc3);

    search.indexDoc(dataset.getDataset().at(1));
    search.indexDoc(dataset.getDataset().at(2));
    search.indexDoc(dataset.getDataset().at(3));

    cout << "Enter the search string:" << endl;
    getline(cin, searchString);

    set<int> s = search.searchDoc(searchString);

    for (const auto &it : s)
    {
        cout << it << endl;
    }

    return 0;
}
