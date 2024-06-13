// Amazing Sport Training Centre currently have six athletes enrolled on their training program,
//The admin of the program can insert, update training plan and add customer’s information 
//This program will calculate discount of the total cost according to theirs passed yoga poses
//The customer can get 5% discount if the customer can pass above a maximum five poses (get 1% for one yoga pose)
//Customer can receive a maximum of five hours’ private coaching a week
//All prices and costs should be displayed as currency to two decimal places
#include<iostream>
#include<ctype.h>
#include<iomanip>

using namespace std;
int TRAINING_PLAN = 0;
int CUSTOMER_COUNT  = 0;
int POSES = 0;

class TrainingPlan{ //Base class
    string training_PlanName;
    int sessionsPerWeek;
    float feesPerWeek;
    public:
        TrainingPlan(){
        string training_PlanName = "";
        int sessionsPerWeek = 0;
        float   feesPerWeek = 0;
        }
        TrainingPlan(string n, int s, float fpw){
            training_PlanName = n;
            sessionsPerWeek = s;
            feesPerWeek = fpw;
            TRAINING_PLAN++;
        }
         void setPlan(){ //to set plan for admin
            cout<<"Enter plan name : ";
            cin.get();
            getline(cin, training_PlanName);
            cout<<"Sesion per week for this plan : ";
            cin>>sessionsPerWeek;
            cout<<"Fees per week for this plan: ";
            cin>>feesPerWeek;
            cout<<"Successfully created a training plan("<<training_PlanName<<")!\n";
            cin.get();
            TRAINING_PLAN++;
        }
        void updatePlan(){ //to update plan for admin
            cout<<"Plan name("<<training_PlanName<<") : \n";
            cout<<"Sessions per week (current sessions - "<<sessionsPerWeek<<") : ";
            cin>>sessionsPerWeek;
            cout<<"Fees per week (current fee - "<<feesPerWeek<<") : ";
            cin>>feesPerWeek;
            cout<<"Successfully updated the training plan("<<sessionsPerWeek<<")!\n";
            cin.get();
        } 
        string getPlanName() {return training_PlanName;}
        float getFeesPerWeek() {return feesPerWeek;}
        int getSessionsPerWeek() {return sessionsPerWeek;}
        void displayPlan(){
            cout<<setw(20)<<training_PlanName
                <<setw(20)<<sessionsPerWeek
                <<setw(15)<<feesPerWeek;
        }
};
class Customer{ //Base class
    string name;
    TrainingPlan trainingPlan;
    float currentWeight;
    string learntPoses[10];
    int privateHours[4];
    bool onlineOffline[4];
    int PosesCount;
    float cost;
    public:
        Customer(){
            name = "";
            currentWeight = 0;
            cost = 0;
            PosesCount = 0;
            for(int i=0; i<4; i++){
                privateHours[i] = 0;
                onlineOffline[i] = false;
            }
        }
        Customer(string n, TrainingPlan tp, float w, int h[4], bool of[4]){
            name = n;
            trainingPlan = tp;
            currentWeight = w;
            cost = 0;
            for(int i=0; i<4; i++){
                privateHours[i] = h[i];
                onlineOffline[i] = of[i];
            }
            CUSTOMER_COUNT++;
        }
        string setCustomer(TrainingPlan plans[]){
            int planIndex = 0;
            cout<<"Enter customer name : ";
            cin.get();
            getline(cin, name);

            trainingPlanLabel:
            cout<<"Available training plans to take : \n";
            for(int i=0; i<TRAINING_PLAN; i++){
                cout<<"Plan : "<<i+1<<" "<<plans[i].getPlanName();
                if(i+1!=TRAINING_PLAN) cout<<" ,\n";
            }
            cout<<"\nEnter the number : ";
            if(planIndex < 0 || planIndex > TRAINING_PLAN) goto trainingPlanLabel;
            cin>>planIndex;
            trainingPlan = plans[planIndex-1];

            cout<<"Enter weight : ";
            cin>>currentWeight;
            char y_n = 'y';
            for(int i=0; i<4; i++){
                cout<<"Week "<<i+1<<": private hours";
                cin>>privateHours[i];

                if(privateHours[i]==0) {
                    onlineOffline[i] = false;
                    break;
                }

                cout<<"Online or offline(y/n) : ";
                cin>>y_n;
                if(y_n == 'y') onlineOffline[i] = true;
                else onlineOffline[i] = false;
            }
            CUSTOMER_COUNT++;
            return trainingPlan.getPlanName();
        }
        string updateCustomer(TrainingPlan plans[]){
            int planIndex = 0;
            cout<<"Customer name(current name - "<<name<<") : \n";

            trainingPlanLabel:
            cout<<"Available training plans to take (current plan - "<<trainingPlan.getPlanName()<<") : \n";
            for(int i=0; i<TRAINING_PLAN; i++){
                cout<<"Plan : "<<i+1<<" "<<plans[i].getPlanName();
                if(i+1!=TRAINING_PLAN) cout<<" ,\n";
            }
            cout<<"\nEnter the number : ";
            if(planIndex < 0 || planIndex > TRAINING_PLAN) goto trainingPlanLabel;
            cin>>planIndex;
            trainingPlan = plans[planIndex-1];

            cout<<"Enter weight (current weight - "<<currentWeight<<") \n";
            cin>>currentWeight;
            char y_n = 'y';
            for(int i=0; i<4; i++){
                cout<<"Week "<<i+1<<": private hours";
                cin>>privateHours[i];

                if(privateHours[i]==0) {
                    onlineOffline[i] = false;
                    break;
                }

                cout<<"Online or offline(y/n) : ";
                cin>>y_n;
                if(y_n == 'y') onlineOffline[i] = true;
                else onlineOffline[i] = false;
            }

            return trainingPlan.getPlanName();
        }
        void displayPoses(){ //to show customer poses that learnt
            cout<<setw(40)<<"Learnt poses : ";
            for(int i=0; i<PosesCount; i++){
                cout<<learntPoses[i];
                if(i+1!=PosesCount) cout<<" ,";
            }
        }
        void addLearntPoses(string poses[]){ //to add customer's lerant poses
            char learnt = 'y';
            int ind = 0;
            int learntInd = 0;
            cout<<"Already learnt poses? (y/n) : ";
            cin>>learnt;
            if(learnt=='y') {
                for(int i=0; i<10; i++){
                    cout<<"("<<i+1<<")"<<poses[i];
                    if(i+1 != 10) cout<<" , ";
                }
                while(true){
                    char more = 'y';
                    cout<<"\nEnter pose index : ";
                    cin>>ind;
                    cout<<"Got more?(y/n) : ";
                    cin>>more;
                    PosesCount++;
                    learntPoses[learntInd] = poses[ind-1];
                    learntInd++;
                    if(more!='y') break;
                }
            }
            cout<<endl;
        }
        float getFinalCost(){
            int count = PosesCount;
            if(PosesCount > 5) count = 5;
            cost = 0;
            cost += trainingPlan.getFeesPerWeek() * 4;
            
            for(int i=0; i<4; i++){
                if(onlineOffline[i]) cost += privateHours[i] * 15000;
                else cost += privateHours[i] * 17000;
            }
            return cost - (cost*count)/100;
        }
        float getCost() {
            cost = 0; 
            cost += trainingPlan.getFeesPerWeek()*4;
            
            for(int i=0; i<4; i++){
                if(onlineOffline[i]) cost += privateHours[i] * 15000;
                else cost += privateHours[i] * 17000;
            }
            return cost;
        }
        void displayCustomer(){ //to show customer
            cout<<setw(20)<<name
                <<setw(20)<<trainingPlan.getPlanName()
                <<setw(10)<<currentWeight
                <<setw(25)<<PosesCount
                <<setw(20)<<getFinalCost();
        }
        void displayCustomerDetails(){ //to show customer in details
            int online = 0, offline = 0;
            for(int i=0; i<4; i++){
                if(onlineOffline[i]) online++;
                else offline++;
            }
            cout<<setw(40)<<"Customer name : "<<setw(20)<<name<<endl
                <<setw(40)<<"Weight : "<<setw(20)<<currentWeight<<endl
                <<setw(40)<<"Training plan : "<<setw(20)<<trainingPlan.getPlanName()<<endl;
            displayPoses();
            cout<<endl<<setw(40)<<"Sessions per week : "<<setw(20)<<trainingPlan.getSessionsPerWeek()<<endl
                <<setw(40)<<"Training plan fees(week/month) : "<<setw(20)<<trainingPlan.getFeesPerWeek()
                <<setw(20)<<trainingPlan.getFeesPerWeek()*4<<endl
                <<setw(40)<<"Online private hours(15000) : "<<setw(20)<<online<<setw(20)<<15000*online<<endl
                <<setw(40)<<"Online private hours(17000) : "<<setw(20)<<offline<<setw(20)<<17000*offline<<endl
                <<setw(40)<<"Cost : "<<setw(20)<<getCost()<<endl
                <<setw(40)<<"DISCOUNT (%) : "<<setw(20)<<PosesCount<<setw(20)<<getCost()*PosesCount/100<<endl
                <<setw(40)<<"Final Cost : "<<setw(20)<<""<<setw(20)<<getFinalCost()<<endl;
            cin.get();
        }
};
void merge(Customer arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Customer* L = new Customer[n1];
    Customer* R = new Customer[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].getFinalCost() <= R[j].getFinalCost()) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}
void mergeSort(Customer arr[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
class Position{ //Base Class
    string positionName;
    int poseCount;
    public:
        string poseType[10];
        string poseName[10];
        Position(){
            positionName = "";
            poseCount = 0;
        }
        Position(string name, string type[10], string names[10], int pc){
            poseCount = pc;
            positionName = name;
            for(int i=0; i<poseCount; i++){
                poseType[i] = type[i];
                poseName[i] = names[i];
            }
            POSES++;
        }
        void addPosition(){ //to add position 
            cout<<"Position name : "<<positionName<<endl;
            cout<<"Positions \n";
            for(int i=0; i<poseCount; i++) {
                cout<<poseName[i];
                if(i+1 != poseCount) cout<<" , ";
                else cout<<endl;
            }
            if(poseCount == 10) {
                cout<<"10 poses already added\n";
                cin.get();
                return;
            }
            char more = 'y';
            while(true){
                if(poseCount==10) break;
                cin.get();
                cout<<"Enter position name("<<poseCount+1<<") : ";
                getline(cin,poseName[poseCount]);
                cout<<"Enter position type("<<poseCount+1<<") : ";
                getline(cin,poseType[poseCount]);
                cout<<"Successfully added("<<poseName[poseCount]<<")\n";
                poseCount++;

                moreLabel:
                cout<<"Add more?(y/n) : ";
                cin>>more;
                if(more=='n') break;
            }
            cin.get();
        }
        void createPosition(){ //to create new position
            cout<<"Enter position name : ";
            cin.get();
            getline(cin,positionName);
            poseCount = 0;
            addPosition();
            POSES++;
        }
        void displayPosition(){
            cout<<setw(20)<<positionName<<endl;
            for(int i=0; i<poseCount; i++){
                cout<<setw(25)<<""
                    <<setw(30)<<poseType[i]
                    <<setw(30)<<poseName[i]
                    <<endl;
            }
        }
};
void displayTrainingPlans(TrainingPlan plans[]);
void displayYogaPositions(Position poses[]);
void displayCustomers(Customer customers[]);
int main(){
    int menuCode; // this is the menu label
    Position poses[5];
    string basicPoseType[10] = {"Standing Pose","Standing Pose","Standing Pose","Standing Pose","Balancing Pose","Balancing Pose",
    "Balancing Pose","Balancing Pose","Seat Pose","Backend Pose"};
    string basicPoseNames[10] ={"Archer Pose","Dolphin Pose","Frog Pose","Fallen Triangle","Big Toe Pose","Lion Pose",
    "Airplane Pose","Side Lunge","Side Reclining","Bird Dog Pose"};
    Position pose1("BASIC",basicPoseType,basicPoseNames,10);
    
    string imPoseType[10] = {"Standing Pose","Standing Pose","Standing Pose","Standing Pose","Balancing Pose",
    "Balancing Pose","Balancing Pose","Balancing Pose","Seat Pose","Backend Pose"};
    string imPoseNames[10] ={"Downward Facing Pose","Mountain Pose","Warrior Pose","Traingle Triangle","Low Lunge",
    "Tree Pose","Plank Pose","Bridge Lunge","Staff Pose","Cobbler's Pose"};
    Position pose2("INTERMEDIATE",imPoseType,imPoseNames,10);
    
    poses[0] = pose1;
    poses[1] = pose2;
    
    TrainingPlan plans[7];
    TrainingPlan basic("BASIC",3,25000);
    TrainingPlan inter("INTERMEDIATE",3,35000);
    TrainingPlan advan("ADVANCED",2,50000);
    plans[0] = advan;
    plans[1] = inter;
    plans[2] = basic;

    Customer customers[50];
    int h1[4] = {0,0,0,0};
    bool of1[4] = {0,0,0,0};
    int h2[4] = {3,1,0,0};
    bool of2[4] = {0,0,0,0};
    int h3[4] = {1,1,1,1};
    bool of3[4] = {1,1,1,1};
    int h4[4] = {0,0,2,0};
    bool of4[4] = {0,0,0,0};
    int h5[4] = {0,0,0,0};
    bool of5[4] = {0,0,0,0};
    Customer customer1("Fuzzy", plans[0], 55, h1, of1);
    Customer customer2("Ye Htet", plans[0], 60, h2, of2);
    Customer customer3("Htet Htet", plans[1], 56, h3, of3);
    Customer customer4("Levi", plans[1], 66, h4, of4);
    Customer customer5("Naing", plans[1], 48, h5, of5);

    customers[0] = customer1;
    customers[1] = customer2;
    customers[2] = customer3;
    customers[3] = customer4;
    customers[4] = customer5;

    menuLabel: // to go menulabel
    cout<<"*********************************************************\n"
        <<setw(50)<<"Welcome from Amazing Sport Yoga System!\n"
        <<setw(43)<<"Ye Htet Naing HND 29th Batch\n"
        <<setw(44)<<"Youth International University\n"
        <<"*********************************************************\n";
    cin.get();
    cout<<"Here are all the menu options available!\n" // these are the choices of this program for addmin
        <<"\n1. Training plan menu."
        <<"\n2. Yoga poses menu."
        <<"\n3. Customers menu."
        <<"\n0. Quit program\n";
    cin>>menuCode;
    if(menuCode==1) {
        tpLabel:
        int trainingPlanMenuCode = 0;
        cout<<"1. Show all training plans."
            <<"\n2. Create a training plan."
            <<"\n3. Update a training plan."
            <<"\n0. Return to main screen.\n";
        cin>>trainingPlanMenuCode;
      
        if(trainingPlanMenuCode < 0 || trainingPlanMenuCode > 3) goto tpLabel;
        if(trainingPlanMenuCode == 0) goto menuLabel;
        else if(trainingPlanMenuCode == 1) {
            displayTrainingPlans(plans);
        }
        else if(trainingPlanMenuCode == 2) {
            plans[TRAINING_PLAN].setPlan();
        }
        else if(trainingPlanMenuCode == 3) {
            int index = 0;
            displayTrainingPlans(plans);
            cout<<"Enter number to update : ";
            cin>>index;
            plans[index-1].updatePlan();
        }
        goto tpLabel;
    } 
    else if(menuCode==2){
        yogaLabel:
        int yogaPoseScreenCode = 0;
        cout<<"1. Display yoga plans."
            <<"\n2. Create a yoga plan."
            <<"\n3. Add yoga poses."
            <<"\n0. Return to main screen.\n";
        cin>>yogaPoseScreenCode;
        if(yogaPoseScreenCode < 0 || yogaPoseScreenCode > 3) goto yogaLabel;
      
        if(yogaPoseScreenCode == 0) goto menuLabel;
        else if(yogaPoseScreenCode == 1) {
            displayYogaPositions(poses);
        }
        else if(yogaPoseScreenCode == 2) {
            poses[POSES].createPosition();
        }
        else if(yogaPoseScreenCode == 3) {
            int index = 0;
            displayYogaPositions(poses);
            cout<<"\nEnter yoga plan index to add : ";
            cin>>index;
            poses[index-1].addPosition();
        }
        goto yogaLabel;
    }
    else if(menuCode==3){
        cusLabel:
        int customerScreenCode = 0;
        cout<<"1. View all customers."
            <<"\n2. Register a new customer."
            <<"\n3. Update a customer."
            <<"\n4. Calculate costs for the customer."
            <<"\n0. Return to main screen. \n";
        cin>>customerScreenCode;
        if(customerScreenCode < 0 || customerScreenCode > 4) goto cusLabel;
      
        if(customerScreenCode == 0) goto menuLabel;
        else if(customerScreenCode == 1) {
            mergeSort(customers, 0, CUSTOMER_COUNT-1);
            displayCustomers(customers);
        }
        else if(customerScreenCode == 2) {
            string planName = customers[CUSTOMER_COUNT].setCustomer(plans);
            if(planName == "INTERMEDIATE") customers[CUSTOMER_COUNT-1].addLearntPoses(poses[0].poseName);
            else if(planName == "ADVANCED") customers[CUSTOMER_COUNT-1].addLearntPoses(poses[1].poseName);
            customers[CUSTOMER_COUNT-1].displayCustomerDetails();
        }
        else if(customerScreenCode == 3) {
            int index = 0;
            displayCustomers(customers);
            cout<<"Enter number to update : ";
            cin>>index;
            string planName = customers[index-1].updateCustomer(plans);
            if(planName == "INTERMEDIATE") customers[index-1].addLearntPoses(poses[0].poseName);
            else if(planName == "ADVANCED") customers[index-1].addLearntPoses(poses[1].poseName);
        }
        else if(customerScreenCode == 4) {
            int index = 0;
            displayCustomers(customers);
            cout<<"Enter number to calculate costs : ";
            cin>>index;
            customers[index-1].displayCustomerDetails();
        }
        goto cusLabel;
    }
    else if(menuCode==0) return 0;
    else goto menuLabel;
}

void displayTrainingPlans(TrainingPlan plans[]){ // to show training plan
    cout<<setw(5)<<"No"
        <<setw(20)<<"Plan name"
        <<setw(20)<<"Session per week"
        <<setw(15)<<"Fees per week"
        <<endl;
    for(int i=0; i<TRAINING_PLAN; i++) {
        cout<<setw(5)<<i+1;
        plans[i].displayPlan();
        cout<<endl;
    }
}

void displayYogaPositions(Position poses[]){ // to show yoga position
    cout<<setw(5)<<"No"
        <<setw(20)<<"Position names"
        <<setw(30)<<"Pose type"
        <<setw(30)<<"Pose name"
        <<endl;
    for(int i=0; i<POSES; i++) {
        cout<<setw(5)<<i+1;
        poses[i].displayPosition();
        cout<<endl;
    }
}
void displayCustomers(Customer customers[]){ 
    cout<<setw(5)<<"No"
        <<setw(20)<<"Customer name"
        <<setw(20)<<"Training plan"
        <<setw(10)<<"Weight"
        <<setw(25)<<"Learnt poses count"
        <<setw(20)<<"Total cost"
        <<endl;
    for(int i=0; i<CUSTOMER_COUNT; i++) {
        cout<<setw(5)<<i+1;
        customers[i].displayCustomer();
        cout<<endl;
    }
}