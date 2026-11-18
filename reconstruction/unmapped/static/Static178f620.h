// Source exposure: binary-analysis; no external implementation source reused.
// Static178f620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f620*);
    virtual void release(Static178f620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f620*);
struct Static178f620 {
    void* value;
    Static178f620();
    ~Static178f620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
