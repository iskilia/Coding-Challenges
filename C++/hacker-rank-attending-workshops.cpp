//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops{
    int start_time, duration, end_time;
};

struct Available_Workshops{
    int num_workshops;
    vector<Workshops> available_workshops;
};

bool compare(Workshops &w1, Workshops &w2){
    return w1.end_time < w2.end_time;
}

Available_Workshops * initialize(int * start_time, int * duration, int n){
    Available_Workshops * ret = new(Available_Workshops);
    Workshops w;
    ret->num_workshops = n;
    for(int i = 0; i < n; i++){
        w.start_time=start_time[i];
        w.duration=duration[i];
        w.end_time=start_time[i]+duration[i];
        ret->available_workshops.push_back(w);
    }
    sort(ret->available_workshops.begin(),ret->available_workshops.end(),compare);
    return ret;
}

int CalculateMaxWorkshops(Available_Workshops* ptr){
    int ret = 0;
    int end_time = 0;
    for(int i = 0; i < ptr->num_workshops; i++){
        if(ptr->available_workshops[i].start_time >= end_time){
            end_time = ptr->available_workshops[i].end_time;
            ret++;
        }
    }
    return ret;
}
