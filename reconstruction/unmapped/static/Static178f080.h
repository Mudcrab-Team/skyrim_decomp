// Source exposure: binary-analysis; no external implementation source reused.
// Static178f080, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f080;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f080*);
    virtual void release(Static178f080*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f080*);
struct Static178f080 {
    void* value;
    Static178f080();
    ~Static178f080() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
