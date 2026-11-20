// Source exposure: binary-analysis; no external implementation source reused.
// Static178f030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f030*);
    virtual void release(Static178f030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f030*);
struct Static178f030 {
    void* value;
    Static178f030();
    ~Static178f030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
