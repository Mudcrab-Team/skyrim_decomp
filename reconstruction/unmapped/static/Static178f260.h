// Source exposure: binary-analysis; no external implementation source reused.
// Static178f260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f260*);
    virtual void release(Static178f260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f260*);
struct Static178f260 {
    void* value;
    Static178f260();
    ~Static178f260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
