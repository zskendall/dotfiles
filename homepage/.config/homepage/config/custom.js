/**
 * Updates the sentinel hrefs on the page.
 *
 * Iterates through all service elements and sets href to current URL. Modified
 * from https://github.com/gethomepage/homepage/discussions/1208#discussioncomment-10863828
 */
const updateSentinelHrefs = () => {
  const SENTINEL = "sentinel";

  // get all text and icon hrefs defined in services.yaml
  const services = Array.prototype.slice.call(
      document.getElementsByClassName("service-title-text"), 0)
    .concat(Array.prototype.slice.call(
      document.getElementsByClassName("service-icon"), 0));

  let addr = window.location.hostname;  // current browser address

  for (let i = 0; i < services.length; i++) {
    if (services[i].getAttribute("href")) {
      let href = services[i].href;
      if (href.includes(SENTINEL)) {
        services[i].href = href.replace(SENTINEL, addr);
      }
    }
  }
};

updateSentinelHrefs();
