// Source exposure: binary-analysis; no external implementation source reused.
// Static178f850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f850*);
    virtual void release(Static178f850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f850*);
struct Static178f850 {
    void* value;
    Static178f850();
    ~Static178f850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
