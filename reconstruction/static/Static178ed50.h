// Source exposure: binary-analysis; no external implementation source reused.
// Static178ed50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ed50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ed50*);
    virtual void release(Static178ed50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ed50*);
struct Static178ed50 {
    void* value;
    Static178ed50();
    ~Static178ed50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
