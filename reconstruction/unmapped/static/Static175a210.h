// Source exposure: binary-analysis; no external implementation source reused.
// Static175a210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a210*);
    virtual void release(Static175a210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a210*);
struct Static175a210 {
    void* value;
    Static175a210();
    ~Static175a210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
