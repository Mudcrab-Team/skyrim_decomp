// Source exposure: binary-analysis; no external implementation source reused.
// Static177ff60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ff60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ff60*);
    virtual void release(Static177ff60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ff60*);
struct Static177ff60 {
    void* value;
    Static177ff60();
    ~Static177ff60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
