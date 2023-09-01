#include "hit_list.h"

hit_list::hit_list() {}

hit_list::hit_list(hitable_obj **l, int n)
{
    hit_obj_list = l;
    list_size = n;
}

// list 안에 있는 오브젝트들을 하나씩 꺼내어 충돌여부를 확인
bool hit_list::hit(const ray &r, float t_min, float t_max, hit_record &rec) const
{
    hit_record tmp_rec;  // rec를 바로 갱신하지 않고, container를 거쳐서 update
    bool is_hit = false;
    double closest_so_far = t_max;
    
    for(int i = 0; i < list_size; ++i)
    {
        // t값을 확인하여, 가장 가까운 지점의 오브젝트만 갱신
        if(hit_obj_list[i]->hit(r, t_min, closest_so_far, tmp_rec))
        {
            is_hit = true;
            closest_so_far = tmp_rec.t;
            rec = tmp_rec;
        }
    }

    return is_hit;
}