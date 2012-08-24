bool RequestHandler::handleRequest(Tufao::HttpServerRequest *request,
                                   Tufao::HttpServerResponse *response,
                                   const QStringList &)
{
    Tufao::Session s(store, *request, *response);

    // ...

    // Here, we provide needed data for the application with perform an action.
    // In the handler that will perform the action, we ignore requests with
    // incorrect tokens.
    (*response) << /* ... */
                << "<input type=\"hidden\" name=\"CSRFToken\" value=\""
                << s["CSRFToken"] << "\">"
                << /* ... */;

    response->end();
    return true;
}
