// Source exposure: binary-analysis; no external implementation source reused.
// Static1769620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769620*);
    virtual void release(Static1769620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769620*);
struct Static1769620 {
    void* value;
    Static1769620();
    ~Static1769620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
