#include <iostream>

template<class CL1>
class Node{
    public: CL1 c_Field;
    public: Node* cp_Next;
    public: Node(CL1 c_Field){
        this->c_Field   = c_Field;
        cp_Next = nullptr;
    }
};

template<class CL1>
class Sp1LS{
    public: Node<CL1>* cp_Start;
    public: Node<CL1>* cp_Curr;
    private: int i_NumNd;

    public: Sp1LS(){
        cp_Start = cp_Curr = nullptr;
        i_NumNd = 0;
    }
    public:~Sp1LS(){
        for(Node<CL1>* op_TmpC= cp_Start;
            op_TmpC != nullptr;){
            Node<CL1>* op_TmpN= op_TmpC->cp_Next;
            delete op_TmpC;
            op_TmpC = op_TmpN;
        }
    }

    public: void fn_Trace(){
        std::cout<< "start->";
        for(Node<CL1>* op_TmpC= cp_Start;
            op_TmpC != nullptr;
            op_TmpC = op_TmpC->cp_Next){

            std::cout<< op_TmpC->c_Field << "->";
        }
        std::cout<< "nullptr" << "\n";
    }

    public: void fn_AddNode(CL1 c_Field){
        Node<CL1>* op_Node = new Node<CL1>(c_Field);
        if(cp_Start == nullptr){
            cp_Start = op_Node;
            cp_Curr = op_Node;
        }
        else{
            cp_Curr->cp_Next = op_Node;
            cp_Curr = op_Node;
        }
        i_NumNd++;
    }

    public: bool fn_DelNode(int i_Ind = 0){
        bool b_IsSuc = true;
        if(i_Ind > (i_NumNd -1)){
            b_IsSuc = false;
        }
        else{
            Node<CL1>* op_TmpC = cp_Start;
            Node<CL1>* op_TmpP = cp_Start;
            for(int i_Ct= 0; i_Ct< (i_Ind + 1); i_Ct++){
                if(i_Ct == 0){
                    continue;
                }
                op_TmpP = op_TmpC;
                op_TmpC = op_TmpC->cp_Next;
            }

            if(i_Ind == 0){
                cp_Start = cp_Start->cp_Next;
                if(i_NumNd == 1){
                    cp_Curr = nullptr;
                }
            }
            else if(i_Ind == (i_NumNd -1) && i_Ind != 0){
                cp_Curr = op_TmpP;
                op_TmpP->cp_Next = nullptr;
            }
            else{
                op_TmpP->cp_Next = op_TmpC->cp_Next;
            }
            delete op_TmpC;
            i_NumNd--;
        }
        return b_IsSuc;
    }

    public: void fn_UpdNode(int i_Ind, CL1 c_Field){

    }

    public: void fn_InsNode(int i_Ind, CL1 c_Field){

    }
};
int main(){
    Sp1LS<int> o_LS;
    o_LS.fn_AddNode(3);
    o_LS.fn_AddNode(7);
    o_LS.fn_AddNode(6);
    o_LS.fn_AddNode(4);
    o_LS.fn_AddNode(2);

    o_LS.fn_Trace();

    o_LS.fn_DelNode(0);
    o_LS.fn_DelNode(1);
    o_LS.fn_Trace();
    return 0;
}
