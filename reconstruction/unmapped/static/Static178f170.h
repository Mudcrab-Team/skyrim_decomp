// Source exposure: binary-analysis; no external implementation source reused.
// Static178f170, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f170;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f170*);
    virtual void release(Static178f170*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f170*);
struct Static178f170 {
    void* value;
    Static178f170();
    ~Static178f170() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
