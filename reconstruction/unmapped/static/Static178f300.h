// Source exposure: binary-analysis; no external implementation source reused.
// Static178f300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f300*);
    virtual void release(Static178f300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f300*);
struct Static178f300 {
    void* value;
    Static178f300();
    ~Static178f300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
