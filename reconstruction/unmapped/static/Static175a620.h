// Source exposure: binary-analysis; no external implementation source reused.
// Static175a620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a620*);
    virtual void release(Static175a620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a620*);
struct Static175a620 {
    void* value;
    Static175a620();
    ~Static175a620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
