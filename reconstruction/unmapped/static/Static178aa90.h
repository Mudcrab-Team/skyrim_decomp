// Source exposure: binary-analysis; no external implementation source reused.
// Static178aa90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178aa90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178aa90*);
    virtual void release(Static178aa90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178aa90*);
struct Static178aa90 {
    void* value;
    Static178aa90();
    ~Static178aa90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
