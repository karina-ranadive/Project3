class Tree {
    Nonprofit *root;
    Nonprofit target;
public:
    Tree(Nonprofit target, map<string, Nonprofit>& orgs);
    void CalculateMatch(Nonprofit& comp);
    bool IsEmpty();
};