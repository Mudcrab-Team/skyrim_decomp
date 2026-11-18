// Source exposure: binary-analysis; no external implementation source reused.
// Static175f850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f850*);
    virtual void release(Static175f850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f850*);
struct Static175f850 {
    void* value;
    Static175f850();
    ~Static175f850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
